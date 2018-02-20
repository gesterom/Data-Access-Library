#include "../DAL/DAL.h"

TEST(getReferenceSimple_test, get){
	DAL::Reference<int> ref(new Loader<int>());
	ref.get()=10;
	EXPECT_EQ(10,ref.get());
}
TEST(getReferenceSimple_test, get_two_gets){
	DAL::Reference<int> ref(new Loader<int>());
	ref.get()=10;
	DAL::Reference<int> ggg(new Loader<int>());
	EXPECT_EQ(10,ggg.get());
}