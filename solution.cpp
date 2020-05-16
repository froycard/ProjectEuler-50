#include<iostream>
#include<cmath>
#include<vector>
using namespace std; 
  
bool IsPrime(unsigned n) {
  if (n <= 1) return false;
  if(n==2) return true;
  if (n % 2 == 0) return false;
  for (auto j=3; j<=sqrt(n); j++) {
    if (n%j==0) {
      return false;
    }
  }      
  return true;
}
 
int main() 
{ 
	const unsigned upperBound = 1000000;
	unsigned maxim = 0, number = 0;
	vector<unsigned> primes;
	for(auto i = 2; i < upperBound; ++i)
		if(IsPrime(i)) primes.push_back(i);

	for(auto i = 0; i < upperBound; ++i)
	{
		if((i+maxim)>primes.size()) break;
		vector<unsigned> chain(&primes[i],&primes[i]+maxim);
		
		for(auto j = chain.size()+i; j < upperBound; ++j)
		{
			chain.push_back(primes[j]);
			unsigned sum=0;
			for(auto k: chain) sum+=k;
			if(sum>upperBound) break;
			if(IsPrime(sum))
			{
				auto size = chain.size();
				if(size>maxim)
				{
					number=sum;
					maxim=size;
					//cout << number << ":" << maxim << endl;
				}
			}
		}
	}
	cout<<"Sol.: "<<number<<endl;
	
	return 0; 
}
