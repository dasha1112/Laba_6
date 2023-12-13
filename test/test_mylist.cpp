#include "MyList.h"
#include "gtests.h"

/*TEST(TListTest, ConstructorTest)
{
  TList<int> list;
  ASSERT_EQ(list.GetBegin(), nullptr);
  ASSERT_EQ(list.GetEnd(), nullptr);
  ASSERT_EQ(list.GetCount(), 0);
}
TEST(TListTest, CopyConstructorTest) 
{
  TList<int> p;
  p.PushEnd(new int(1));
  p.PushEnd(new int(2));
  p.PushEnd(new int(3));

  TList<int> list(p);

  TNode<int>* temp1 = p.GetBegin();
  TNode<int>* temp2 = list.GetBegin();

  while (temp1 != nullptr && temp2 != nullptr) {
    ASSERT_EQ(*temp1->GetData(), *temp2->GetData());
    temp1 = temp1->GetNext();
    temp2 = temp2->GetNext();
  }
  ASSERT_EQ(temp1, nullptr);
  ASSERT_EQ(temp2, nullptr);
}
TEST(TListTest, DestructorTest) 
{
  TList<int> list;
  list.PushEnd(new int(1));
  list.PushEnd(new int(2));
  list.PushEnd(new int(3));

  int initialCount = list.GetCount();

  list.~TList();

  ASSERT_EQ(list.GetBegin(), nullptr);
  ASSERT_EQ(list.GetEnd(), nullptr); 
  ASSERT_EQ(list.GetCount(), 0);
}
TEST(TListTest, AssignmentOperatorTest) 
{
  TList<int> list1;
  list1.PushEnd(new int(1));
  list1.PushEnd(new int(2));
  list1.PushEnd(new int(3));

  TList<int> list2;
  list2.PushEnd(new int(4));
  list2.PushEnd(new int(5));

  list1 = list2;

  TNode<int>* temp1 = list1.GetBegin();
  TNode<int>* temp2 = list2.GetBegin();
  while (temp1 != nullptr && temp2 != nullptr) {
    ASSERT_EQ(*temp1->GetData(), *temp2->GetData());
    temp1 = temp1->GetNext();
    temp2 = temp2->GetNext();
  }
  ASSERT_EQ(temp1, nullptr);
  ASSERT_EQ(temp2, nullptr);
}
TEST(TListTest, PushBeginTest) {
  TList<int> list;
  int firstData = 1;
  int secondData = 2;

  list.PushBegin(new int(secondData));
  list.PushBegin(new int(firstData));

  ASSERT_NE(list.GetBegin(), nullptr);
  ASSERT_NE(list.GetEnd(), nullptr);
  ASSERT_EQ(*list.GetBegin()->GetData(), firstData);
  ASSERT_EQ(*list.GetEnd()->GetData(), secondData);
}
TEST(TListTest, PushEndTest) 
{
  TList<int> list;
  int firstData = 1;
  int secondData = 2;

  list.PushEnd(new int(firstData));
  list.PushEnd(new int(secondData));

  ASSERT_NE(list.GetBegin(), nullptr);
  ASSERT_NE(list.GetEnd(), nullptr);
  ASSERT_EQ(*list.GetBegin()->GetData(), firstData);
  ASSERT_EQ(*list.GetEnd()->GetData(), secondData);
}
TEST(TListTest, DelBeginTest) 
{
  TList<int> list;
  int firstData = 1;
  int secondData = 2;

  list.PushEnd(new int(firstData));
  list.PushEnd(new int(secondData));

  list.DelBegin();

  ASSERT_EQ(list.GetCount(), 1);
  ASSERT_EQ(*list.GetBegin()->GetData(), secondData);
  ASSERT_EQ(list.GetEnd(), list.GetBegin());
  ASSERT_EQ(list.GetEnd()->GetPrev(), nullptr);
}
TEST(TListTest, DelEndTest) 
{
  TList<int> list;
  int firstData = 1;
  int secondData = 2;

  list.PushEnd(new int(firstData));
  list.PushEnd(new int(secondData));

  list.DelEnd();

  ASSERT_EQ(list.GetCount(), 1);
  ASSERT_EQ(*list.GetEnd()->GetData(), firstData);
  ASSERT_EQ(list.GetEnd(), list.GetBegin());
  ASSERT_EQ(list.GetBegin()->GetNext(), nullptr);
}

TEST(TListTest, GetBeginTest) 
{
  TList<int> list;
  ASSERT_EQ(list.GetBegin(), nullptr);
}

TEST(TListTest, GetEndTest) 
{
  TList<int> list;
  ASSERT_EQ(list.GetEnd(), nullptr);
}

TEST(TListTest, GetCountTest) 
{
  TList<int> list;
  ASSERT_EQ(list.GetCount(), 0);
}*/