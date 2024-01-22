#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Create{


      	public:
		std::vector<int> create() {
			std::vector<int> v(100);
			std::iota(v.begin(),v.end(),NULL);
                         
	        return v;
		}

          void modifyprint(std::vector<int>&& v) {
	     for(auto &e :v)
		     e *=2;

	       std::cout<<std::accumulate(v.begin(),v.end(), NULL)
		       <<std::endl;
	  }

         std::vector<int> my ={1,2,3,4};  
};





int main(){
   Create obj;


   obj.modifyprint(std::move(obj.my));
   obj.modifyprint(obj.create());


return 0;
}
