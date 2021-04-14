#include <gtest/gtest.h>
#include "SimpleMater.h"

TEST(TEST_MATER, all_nullptr){
  const std::size_t N = sizeof(int);
  float probability = 1;
  Mater<N> m(probability);
  ASSERT_NO_THROW(m.Mate(nullptr, nullptr));

}

TEST(TEST_MATER, creating_new){
  const std::size_t N = sizeof(int);
  float probability = 1;
  Mater<N> m(probability);

  Genome<N> g(1);
  auto children = m.Mate(&g, &g);
  ASSERT_NE(children.size(), 0);
  ASSERT_EQ(children.size(), 2);
}


TEST(TEST_MATER, zero){
  const std::size_t N = sizeof(int);
  const std::size_t max = 2;
  float probability = 0;
  Mater<N> m(probability);

  Genome<N> g(max);
  Genome<N> g2(max);
  g.SetGene(0, 1);
  g2.SetGene(1, 2);
  auto children = m.Mate(&g, &g2);
  ASSERT_EQ(children.size(), 2);
  for (size_t i = 0; i < max; i++) {
    ASSERT_EQ(g.GetGene(i), children[0]->GetGene(i));
    ASSERT_EQ(g2.GetGene(i), children[1]->GetGene(i));
  }

}

//TODO: новые потомки - НЕ копии родителей
TEST(TEST_MATER, for_sure){

  const std::size_t N = sizeof(int);
  const std::size_t max = 2;
  float probability = 1;
  Mater<N> m(probability);

  Genome<N> g(max);
  Genome<N> g2(max);
  g.SetGene(0, 1);
  g2.SetGene(1, 2);
  auto children = m.Mate(&g, &g2);
  ASSERT_EQ(children.size(), 2);
  //до первой половины дети копии родителей
  for (size_t i = 0; i < max/2; i++) {
    ASSERT_EQ(g.GetGene(i), children[0]->GetGene(i));
    ASSERT_EQ(g2.GetGene(i), children[1]->GetGene(i));
  }
  //после половины дети копии другого родителя
  for (size_t i = max/2; i < max; i++) {
  ASSERT_EQ(g2.GetGene(i), children[0]->GetGene(i));
  ASSERT_EQ(g.GetGene(i), children[1]->GetGene(i));
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}