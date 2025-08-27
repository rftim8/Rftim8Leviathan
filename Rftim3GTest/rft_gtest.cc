#include "rft_gtest.hh"

int tester = 10;

class MyFixture : public ::testing::Test
{
protected:
    int *value;

    static void SetUpTestSuite()
    {
        // runs once before all tests
        tester = 42;
    }

    void SetUp() override
    {
        value = new int(tester); // setup logic
    }

    void TearDown() override
    {
        delete value; // cleanup logic
        value = nullptr;
    }

    static void TearDownTestSuite()
    {
        // runs once after all tests
    }
};

TEST_F(MyFixture, ValueIsCorrect)
{
    EXPECT_EQ(*value, 42);
}

TEST_F(MyFixture, ValueIsPositive)
{
    EXPECT_GT(*value, 0);
}

// Function to test
int Add(int a, int b)
{
    return a + b;
}

// Test case for Add function
TEST(AdditionTest, HandlesPositiveNumbers)
{
    EXPECT_EQ(Add(1, 2), 3);
    EXPECT_EQ(Add(10, 20), 30);
}

TEST(AdditionTest, HandlesNegativeNumbers)
{
    EXPECT_EQ(Add(-1, -2), -3);
    EXPECT_EQ(Add(-10, 5), -5);
}

int main(int argc, char **argv)
{
    system("cls");
    // FILE *output_file;
    // std::string output_path;
    std::stringstream test_filter;
    // output_path = LeetCodeOutputFilePath(className);
    test_filter << "*AdditionTest.HandlesNegativeNumbers*"
                   ":"
                   "*AdditionTest.HandlesPositiveNumbers*"
                   ":"
                   "*MyFixture.ValueIsCorrect*"
                   ":"
                   "*MyFixture.ValueIsPositive*";
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = test_filter.str();
    return RUN_ALL_TESTS();

    // UnitTesting(output_file, output_path, test_filter.str());
}

static int UnitTesting(FILE *output_file, std::string output_path, std::string filter)
{
    output_file = freopen(output_path.c_str(), "w", stdout);
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(filter) = filter;
    int res = RUN_ALL_TESTS();
    fclose(output_file);

    return res;
}
