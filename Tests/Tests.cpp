#include "include/gtest.h"
#include "ChunkList/ChunkList.h"

TEST(ChunkListTest, DefaultConstructor) {
fefu_laboratory_two::ChunkList<int, 3> chunkList;

EXPECT_TRUE(chunkList.empty());
EXPECT_EQ(chunkList.get_size(), 0);
EXPECT_EQ(chunkList.max_size(), 0);
EXPECT_EQ(chunkList.begin(), chunkList.end());
}

TEST(ChunkListTest, CustomAllocator) {
using CustomAllocator = fefu_laboratory_two::Allocator<int>;
fefu_laboratory_two::ChunkList<int, 3, CustomAllocator> chunkList;

EXPECT_TRUE(chunkList.empty());
EXPECT_EQ(chunkList.get_size(), 0);
EXPECT_EQ(chunkList.max_size(), 0);
EXPECT_EQ(chunkList.begin(), chunkList.end());
}

TEST(ChunkListTest, InitializerListConstructor) {
fefu_laboratory_two::ChunkList<int, 3> chunkList = {1, 2, 3};

EXPECT_FALSE(chunkList.empty());
EXPECT_EQ(chunkList.get_size(), 3);
EXPECT_EQ(chunkList.max_size(), 3);
EXPECT_EQ(chunkList[0], 1);
EXPECT_EQ(chunkList[1], 2);
EXPECT_EQ(chunkList[2], 3);
}

TEST(ChunkListTest, CopyConstructor) {
fefu_laboratory_two::ChunkList<int, 3> originalList = {1, 2, 3};
fefu_laboratory_two::ChunkList<int, 3> copyList(originalList);

EXPECT_EQ(originalList, copyList);
EXPECT_EQ(originalList.get_size(), copyList.get_size());
}

TEST(ChunkListTest, MoveConstructor) {
fefu_laboratory_two::ChunkList<int, 3> originalList = {1, 2, 3};
fefu_laboratory_two::ChunkList<int, 3> moveList(std::move(originalList));

EXPECT_TRUE(originalList.empty());
EXPECT_EQ(moveList.get_size(), 3);
}

TEST(ChunkListTest, CopyAssignmentOperator) {
fefu_laboratory_two::ChunkList<int, 3> originalList = {1, 2, 3};
fefu_laboratory_two::ChunkList<int, 3> copyList;
copyList = originalList;

EXPECT_EQ(originalList, copyList);
EXPECT_EQ(originalList.get_size(), copyList.get_size());
}

TEST(ChunkListTest, MoveAssignmentOperator) {
fefu_laboratory_two::ChunkList<int, 3> originalList = {1, 2, 3};
fefu_laboratory_two::ChunkList<int, 3> moveList;
moveList = std::move(originalList);

EXPECT_TRUE(originalList.empty());
EXPECT_EQ(moveList.get_size(), 3);
}

TEST(ChunkListTest, Clear) {
fefu_laboratory_two::ChunkList<int, 3> chunkList = {1, 2, 3};
chunkList.clear();

EXPECT_TRUE(chunkList.empty());
EXPECT_EQ(chunkList.get_size(), 0);
EXPECT_EQ(chunkList.max_size(), 0);
}

TEST(ChunkListTest, Swap) {
fefu_laboratory_two::ChunkList<int, 3> list1 = {1, 2, 3};
fefu_laboratory_two::ChunkList<int, 3> list2 = {4, 5, 6};

list1.swap(list2);

EXPECT_EQ(list1.get_size(), 3);
EXPECT_EQ(list2.get_size(), 3);
EXPECT_EQ(list1[0], 4);
EXPECT_EQ(list2[0], 1);
}

TEST(ChunkListTest, Assign) {
fefu_laboratory_two::ChunkList<int, 3> chunkList;
chunkList.assign(5, 42);

EXPECT_EQ(chunkList.get_size(), 5);
EXPECT_EQ(chunkList.front(), 42);
EXPECT_EQ(chunkList.back(), 42);
}

TEST(ChunkListTest, EraseSingleElement) {
fefu_laboratory_two::ChunkList<int, 3> chunkList = {1, 2, 3, 4, 5};
auto it = chunkList.erase(chunkList.begin() + 2);

EXPECT_EQ(chunkList.get_size(), 4);
EXPECT_EQ(*it, 4);
}

TEST(ChunkListTest, EraseRange) {
fefu_laboratory_two::ChunkList<int, 3> chunkList = {1, 2, 3, 4, 5};
auto it = chunkList.erase(chunkList.begin() + 1, chunkList.begin() + 4);

EXPECT_EQ(chunkList.get_size(), 2);
EXPECT_EQ(*it, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
