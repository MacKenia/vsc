#include "frd.h"
using namespace std;
 
fstream frd::frdFile("friends.dat", ios::binary | ios::in | ios::out);

frd::frd()
{
    frdFile.read((char *)fri, sizeof(fri));
}

frd::~frd()
{

}


