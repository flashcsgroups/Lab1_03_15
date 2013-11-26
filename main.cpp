#include <iostream>

using namespace std;
enum inputResult {EOL, ERROR}
int main()
{
    int tryCount = 0;
    List<int>* input = new List<int>();
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
    
    List<int>* temp = input->reverse();
    delete input;
    input = temp;

    int index = 0;
    List<int>* output = new List<int>();
}

void add(List<int>* number, int additive)
{
    List<int>* temp = new List<int>();
    while(additive)
    {
        temp->addLast(additive%10);
        additive/=10;
    }
    add(number, temp);
}

void add(List<int>* number, List<int>* additive)
{
	int index = 0;
	int additionalNumber = 0;
    bool numberEnded = false;
    bool additiveEnded = false;
    
    while(true)
    {
        int tempNumberDigit, tempAdditiveDigit;

        try
            tempNumberDigit = number->getOnIndex(index);
        catch(errors e)
        {
            numberEnded = true;
            break;
        }

        try
            tempAdditiveDigit = additive->getOnIndex(index);
        catch(errors e)
        {
            additiveEnded = true;
            break;
        }

        temp = tempNumberDigit + tempAdditiveDigit + additionalNumber;
        additionalNumber = temp % 10;
        temp /= 10;
        number->setOnIndex(index, temp);

        index++;
    }

    if(numberEnded && additiveEnded)
    {
        if(additionalNumber)
            number->addLast(additionalNumber);
    }
    else if(additiveEnded)
    {
        while(additionalNumber)
        {
            int temp = number->getOnIndex(index);
            temp+=additionalNumber;
            additionalNumber = temp % 10;
            temp /= 10;
            number->setOnIndex(index, temp);
            index++
        }
    }
    else if(numberEnded)
    {
        while(!additiveEnded)
        {
            int temp;
            try
                temp = additive->getOnIndex(index);
            catch(error e)
            {
                additiveEnded = true;
                temp = 0;
            }

            temp += additionalNumber;
            additionalNumber = temp % 10;
            temp /= 10;
            if(!additiveEnded || temp)
                number->addLast(temp);
            index++;
        }
    }
}

void multiply(List<int>* number, int multiplier)
{
    List<int> temp = number->copy;
    for(int i = 0; i < multiplier; i++)
    {
        add(number, &temp);
    }
    delete temp;
}