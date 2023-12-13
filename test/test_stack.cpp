#include "MyNode.h"
#include "gtests.h"
/*TEST(TNodeTest, ConstructorTest)
{
  TNode<int>* nextNode = new TNode<int>(nullptr, nullptr, new int(20));
  TNode<int>* prevNode = new TNode<int>(nullptr, nullptr, new int(30));
  TNode<int> node(nextNode, prevNode, new int(10));
  ASSERT_EQ(*(node.GetData()), 10);
  ASSERT_EQ(node.GetNext(), nextNode);
  ASSERT_EQ(node.GetPrev(), prevNode);
}
TEST(TNodeTest, DefaultConstructorTest) 
{
  TNode<int> node;
  ASSERT_EQ(node.GetNext(), nullptr);
  ASSERT_EQ(node.GetPrev(), nullptr);
  ASSERT_EQ(node.GetData(), nullptr);
}

TEST(TNodeTest, DestructorTest) 
{
  TNode<int>* node = new TNode<int>(nullptr, nullptr, new int(10));
  delete node;
  ASSERT_EQ(node->GetNext(), nullptr);
  ASSERT_EQ(node->GetPrev(), nullptr);
  ASSERT_EQ(node->GetData(), nullptr);
}
TEST(TNodeTest, CopyConstructorTest) 
{
  TNode<int>* originalNode = new TNode<int>(nullptr, nullptr, new int(10));
  TNode<int> node(*originalNode);
  ASSERT_EQ(*(node.GetData()), 10);
  ASSERT_EQ(node.GetNext(), originalNode->GetNext());
  ASSERT_EQ(node.GetPrev(), originalNode->GetPrev());
}
TEST(TNodeTest, AssignmentOperatorTest) 
{
  TNode<int> node1(nullptr, nullptr, new int(10));
  TNode<int> node2(nullptr, nullptr, new int(20));
  node2 = node1;
  ASSERT_EQ(*(node2.GetData()), 10);
  ASSERT_EQ(node2.GetNext(), nullptr);
  ASSERT_EQ(node2.GetPrev(), nullptr);
}
TEST(TNodeTest, GetNextTest) 
{
  TNode<int> node(nullptr, nullptr, new int(10));
  TNode<int> nextNode(nullptr, &node, new int(20));
  node.SetNext(&nextNode);
  ASSERT_EQ(node.GetNext(), &nextNode);
}
TEST(TNodeTest, GetPrevTest) 
{
  TNode<int> node(nullptr, nullptr, new int(10));
  TNode<int> prevNode(&node, nullptr, new int(20));
  ASSERT_EQ(node.GetPrev(), &prevNode);
}
TEST(TNodeTest, GetDataTest) 
{
  int value = 10;
  TNode<int> node(nullptr, nullptr, &value);
  ASSERT_EQ(*(node.GetData()), value);
}*/

