#include "Caesar.h"
#include <gtest/gtest.h>

TEST(Caesar, constructor) {
  Caesar cipher("dog");
  EXPECT_EQ("dog", cipher.get_key());
}

TEST(Caesar, singlechar_encrypt) {
  Caesar key_space(" ");
  Caesar key_exclaim("!");
  Caesar key_a("a");
  Caesar key_z("z");
  //No shift
  EXPECT_EQ("d", key_space.encode("d"));
  //Shift by one
  EXPECT_EQ("e", key_exclaim.encode("d"));
  //Wrap around
  EXPECT_EQ("J", key_a.encode("d"));
  //Extremes
  EXPECT_EQ(" ", key_space.encode(" "));
  EXPECT_EQ("y", key_z.encode("z"));
  EXPECT_EQ("z", key_space.encode("z"));
  EXPECT_EQ("z", key_z.encode(" "));
}

TEST(Caesar, multichar_msg_encrypt) {
  Caesar key_space(" ");
  Caesar key_exclaim("!");
  Caesar key_a("a");
  //No shift
  EXPECT_EQ("dog", key_space.encode("dog"));
  //Shift by one
  EXPECT_EQ("eph", key_exclaim.encode("dog"));
  //Wrap around
  EXPECT_EQ("JUM", key_a.encode("dog"));
}

TEST(Caesar, multichar_encrypt) {
  Caesar key_space2("  ");
  //No shift - even multiple
  EXPECT_EQ(            "The quick brown fox jumped over the lazy dog",
      key_space2.encode("The quick brown fox jumped over the lazy dog"));
  //No shift - uneven multiple
  Caesar key_space3("   ");
  EXPECT_EQ(            "The quick brown fox jumped over the lazy dog",
      key_space3.encode("The quick brown fox jumped over the lazy dog"));
  //Shift by a, even multiple
  Caesar key_a2("aa");
  EXPECT_EQ(         ":NKaW[OIQaHXU]TaLU^aP[SVKJaU\\KXaZNKaRG`_aJUM",
      key_a2.encode("The quick brown fox jumped over the lazy dog")); 
  //Shift by a, uneven multiple
  Caesar key_a3("aaa");
  EXPECT_EQ(         ":NKaW[OIQaHXU]TaLU^aP[SVKJaU\\KXaZNKaRG`_aJUM",
      key_a3.encode("The quick brown fox jumped over the lazy dog")); 
  //sequencing, even multiple
  Caesar key_do("do");
  EXPECT_EQ(         "=\\NoZiRWToKfXkWoOcaoSiVdNXdc_Y[o]\\NoUUcmdXX[",
      key_do.encode("The quick brown fox jumped over the lazy dog")); 
  //sequencing, uneven multiple: note the escaped backslash
  Caesar key_dog("dog");
  EXPECT_EQ(       "=\\QdeaRWWdV^XkZdZ[aoV^a\\NXgXjQ[o`QYgUUfboPX[",
      key_dog.encode("The quick brown fox jumped over the lazy dog")); 
  // msg smaller than key
  EXPECT_EQ( "=", key_dog.encode("T"));
}

TEST(Caesar, singlechar_decrypt) {
  Caesar key_space(" ");
  Caesar key_exclaim("!");
  Caesar key_a("a");
  Caesar key_z("z");
  //No shift
  EXPECT_EQ("d", key_space.decode("d"));
  //Shift by one
  EXPECT_EQ("d", key_exclaim.decode("e"));
  //Wrap around
  EXPECT_EQ("d", key_a.decode("J"));
  //Extremes
  EXPECT_EQ(" ", key_space.decode(" "));
  EXPECT_EQ(" ", key_z.decode("z"));
  EXPECT_EQ("z", key_space.decode("z"));
  EXPECT_EQ("z", key_z.decode("y"));
}

TEST(Caesar, multichar_decrypt) {
  Caesar key_space2("  ");
  //No shift - even multiple
  EXPECT_EQ(            "The quick brown fox jumped over the lazy dog",
      key_space2.decode("The quick brown fox jumped over the lazy dog"));
  //No shift - uneven multiple
  Caesar key_space3("   ");
  EXPECT_EQ(            "The quick brown fox jumped over the lazy dog",
      key_space3.decode("The quick brown fox jumped over the lazy dog"));
  //Shift by a, even multiple: note the escaped backslash
  Caesar key_a2("aa");
  EXPECT_EQ(         "The quick brown fox jumped over the lazy dog",
      key_a2.decode( ":NKaW[OIQaHXU]TaLU^aP[SVKJaU\\KXaZNKaRG`_aJUM"));
  //Shift by a, uneven multiple: note the escaped backslash
  Caesar key_a3("aaa");
  EXPECT_EQ(         "The quick brown fox jumped over the lazy dog",
      key_a3.decode( ":NKaW[OIQaHXU]TaLU^aP[SVKJaU\\KXaZNKaRG`_aJUM"));
  //sequencing, even multiple: note the escaped backslash
  Caesar key_do("do");
  EXPECT_EQ(         "The quick brown fox jumped over the lazy dog",
      key_do.decode( "=\\NoZiRWToKfXkWoOcaoSiVdNXdc_Y[o]\\NoUUcmdXX["));
  //sequencing, uneven multiple: note the escaped backslash
  Caesar key_dog("dog");
  EXPECT_EQ( "The quick brown fox jumped over the lazy dog",
      key_dog.decode( "=\\QdeaRWWdV^XkZdZ[aoV^a\\NXgXjQ[o`QYgUUfboPX["));
  // msg smaller than key
  EXPECT_EQ( "T", key_dog.decode("="));
}

int main(int argc, char**argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
