#include <iostream>
using namespace std;

class ManagedArray{
  private:
    float* elements;
    int numberOfElements;
  public:

    // constructor
    ManagedArray()
    :elements(NULL),
     numberOfElements(0)
    { }
    
    ManagedArray(const ManagedArray& ma){
     elements = new float;
     *elements = *ma.elements; // copy the value
    }  
    
    // destructor
    ~ManagedArray(){ 
      delete [] elements;
    }
    
    // mutators
    void add(float value){

  		// make a bigger array to replace the old one
  		float * biggerArray = new float[numberOfElements+1];
  		if(elements != NULL)
  		{
  			// copy the old elements into the biggerArray
  			for(int i = 0; i < numberOfElements; i++)
  			{
  				biggerArray[i] = elements[i];
  			}
  			// the old array is not needed anymore, we have a better copy
  			delete [] elements;
  		}
  		// point at the new array
  		elements = biggerArray;
  
  		// put the new number into the last element of the array
  		numberOfElements = numberOfElements+1;
 
  		elements[numberOfElements-1] = value;
  	
    	return;
    }
    
    // accessors
    int size() const{
      return(numberOfElements);
    }
    
    float get(int index) const{
      return(elements[index]);
    }

    int get_numberOfElements() const{
      return(numberOfElements);
    }
};

void print(ManagedArray ma){

		for(int i = 0; i < ma.get_numberOfElements(); ++i)
		{
			if(i > 0)
			{
				cout << ", ";
			}
			cout << ma.get(i);
		}
		cout << "}" << endl;  
  
  return;
}


int main()
{
  ManagedArray ma = ManagedArray();
	float userInput;
	bool addingNumbersToTheList;
	
	cout << "Keep entering numbers. Enter a non-number to stop." << endl;
	do
	{
		cin >> userInput;
		addingNumbersToTheList = !std::cin.fail();
		if(addingNumbersToTheList) {
      ma.add(userInput);
		}
	}
	while(addingNumbersToTheList);

	// fix cin after intentionally breaking it above.
	if(std::cin.fail())
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
	}

	bool hasNumbers = ma.get_numberOfElements() > 0;
	if(hasNumbers) {
		// print the stored numbers
		cout << "Entered numbers: " << endl;
		cout << "{";
		for(int i = 0; i < ma.get_numberOfElements(); ++i)
		{
			if(i > 0)
			{
				cout << ", ";
			}
			cout << ma.get(i);
		}
		
		print(ma);

		float sum = 0;
		for(int i = 0; i < ma.get_numberOfElements(); ++i)
		{
			sum += ma.get(i);
		}
		cout << "total: " << sum << endl;
		cout << "average: " << (sum / ma.get_numberOfElements()) << endl;
	}
	else
	{
		cout << "no numbers entered." << endl;
	}
	
	return 0;
}
