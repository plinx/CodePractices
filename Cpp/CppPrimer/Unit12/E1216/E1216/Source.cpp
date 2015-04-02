#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr; using std::string;

int main()
{
	unique_ptr<string> p1(new string("Error test"));
	//unique_ptr<string> p2(p1);
	//'std::unique_ptr<std::string,std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)' : attempting to reference a deleted function

	unique_ptr<string> p3;
	//p3 = p1;
	//'std::unique_ptr<std::string,std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)' : attempting to reference a deleted function

	return 0;
}