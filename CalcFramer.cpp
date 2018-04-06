#include <assert.h>
#include "CalcFramer.hpp"

using namespace std;

void CalcFramer::append(string chars)
{
	buffer = buffer + chars;
}

bool CalcFramer::hasMessage() const
{
	for(int i = 0; i < buffer.length(); i++){
		if(buffer.at(i) == '\n' || buffer.at(i) == '\r'){
			return true;
		}
	}
	return false;
}

string CalcFramer::topMessage() const
{
	if(!hasMessage()){
		return "";
	}
	else{
		std::string str;
		for(int i = 0; i < buffer.length(); i++){
			if(buffer.at(i) != '\n' || buffer.at(i) != '\r'){
				str = str + buffer.at(i);
			}
			else{
				return str;
			}
		}
	}
}

void CalcFramer::popMessage()
{
	std::string curMessage = this->topMessage();
	
}

void CalcFramer::printToStream(ostream& stream) const
{
	// (OPTIONAL) PUT YOUR CODE HERE--useful for debugging
}
