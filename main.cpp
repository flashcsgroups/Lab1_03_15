#include <iostream>
#include <limits>
#include "List.cpp"

using namespace std;
enum inputResult {EOL, ERROR};

void add(List<int>*, int);
void add(List<int>*, List<int>*);
void multiply(List<int>*, int);

int main()
{
    int tryCount = 0;
    List<int>* input;
    cout << "Enter string to process: ";
    while(true)
    {
    	try
    	{
            input = new List<int>();
    		int buffer;
    		int inputCount = 0;
		    while(true)
		    {
		    	buffer = cin.get();
                inputCount++;
		    	if(buffer==10)
		    		throw EOL;
		    	if(buffer>55 || buffer<48 || inputCount>300)
		    		throw ERROR;
		    	input->addLast(buffer-48);
		    }
    	}
    	catch(inputResult result)
    	{
    		tryCount++;
    		if(result==EOL)
				break;
    		else
            {
				cout << "Incorrect input, ";
                delete input;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if(tryCount<2)
					cout << "try again, enter string to process: ";
				else
				{
					cout << "exited" << endl;
					return 1;
				}
            }
    	}
    }

    List<int>* temp = input->reverse();
    delete input;
    input = temp;

    List<int>* multiplier = new List<int>();
    multiplier->addLast(1);
    List<int>* output = new List<int>();
    output->addLast(0);
    for(int index = 0; index < input->getLength(); index++)
    {
        List<int>* temp = multiplier->copy();
        multiply(temp, input->getOnIndex(index));
        add(output, temp);
        delete temp;
        multiply(multiplier, 8);
    }

    temp = output->reverse();
    delete output;
    output = temp;

    for(int index = 0; index < output->getLength(); index++)
    {
        cout << output->getOnIndex(index);
    }
    cout << endl;
    return 0;
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
        {
            tempNumberDigit = number->getOnIndex(index);
        }
        catch(errors e)
        {
            numberEnded = true;
            break;
        }

        try
        {
            tempAdditiveDigit = additive->getOnIndex(index);
        }
        catch(errors e)
        {
            additiveEnded = true;
            break;
        }

        int temp = tempNumberDigit + tempAdditiveDigit + additionalNumber;
        additionalNumber = temp / 10;
        temp %= 10;
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
            additionalNumber = temp / 10;
            temp %= 10;
            number->setOnIndex(index, temp);
            index++;
        }
    }
    else if(numberEnded)
    {
        while(!additiveEnded)
        {
            int temp;
            try
            {
                temp = additive->getOnIndex(index);
            }
            catch(errors e)
            {
                additiveEnded = true;
                temp = 0;
            }

            temp += additionalNumber;
            additionalNumber = temp / 10;
            temp %= 10;
            if(!additiveEnded || temp)
                number->addLast(temp);
            index++;
        }
    }
}

void multiply(List<int>* number, int multiplier)
{
    if(multiplier)
    {
        List<int>* temp = number->copy();
        for(int i = 1; i < multiplier; i++)
        {
            add(number, temp);
        }
        delete temp;
    }
    else
    {
        number->clear();
        number->addLast(0);
    }
}