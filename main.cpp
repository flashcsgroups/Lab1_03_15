#include <iostream>

using namespace std;
enum inputResult {EOL, ERROR}
int main()
{
    int tryCount = 0;
    List<int> input;
    cout << "Enter string to process: ";
    while(true)
    {
    	try
    	{
    		int buffer;
    		int inputCount = 0;
		    while(true)
		    {
		    	cin.get(buffer);
		    	if(buffer==10)
		    		throw EOL;
		    	if(buffer>55 || buffer<48 || inputCount>300)
		    		throw ERROR;
		    	input.addLast(buffer);
		    	inputCount++;
		    }
    	}
    	catch(inputResult result)
    	{
    		tryCount++;
    		switch(result)
    		{
    			case EOL:
    				break;
    			case ERROR:
    				cout << "Incorrect input, ";
    				if(tryCount<2)
    					cout << "try again, enter string to process: ";
    				else
    				{
    					cout << "exited";
    					return 1;
    				}
    		}
    	}
    }
    

}

void add(List<int>* number, int additive)
{
	int index = 0;
	
}