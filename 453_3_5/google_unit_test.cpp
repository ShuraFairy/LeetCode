#include <gtest/gtest.h>


TEST(Matrixtest, operatorset) 
{
	//Matrix<int, -1> matrix;
	//matrix[1][1] = -1;
	//EXPECT_EQ(matrix[1][1], -1);
	//EXPECT_EQ(matrix.size(), 0);
	//matrix[100][100] = 314;
	//EXPECT_EQ(matrix[100][100], 314);
	//EXPECT_EQ(matrix.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
