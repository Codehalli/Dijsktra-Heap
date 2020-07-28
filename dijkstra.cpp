/*
 *  Purpose for program:
 *  This programming project is understanding and implementing dijkstra algorithm and heaps
 *
 *  dijkstra.hpp
 *  Programmer: Pranav Rao
 *  Date: December 18, 2019
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#include "heap_priority_queue.hpp"

#include "fstream"
#include "list.hpp"

#include <math.h>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {

    std::string inputFilename; //declaring the inputfile name
    inputFilename = "graph.csv";

    std::ifstream inputFile; //calling the input file;
    inputFile.open(inputFilename); //opening the file

    std::pair<int,int> insert; //creating and insert pair
    List< std::pair<int,int> > g[20];

    std::string dum;  //creating two dummy variables for ref
    std::string dumOne;
    std::stringstream point;

    int dum3;  //declaring and intiallizing the varaibles
    int col = 1; int pa = 1; int vx = 0;

    if(!inputFile.good()) //check to see if the input file opens
    {
        return 0; //retun the 0;
    }

    while(std::getline(inputFile,dum)) //using get line read the variable in the file
    {
        point.clear(); //clar the pointer
        point << dum;

        while(std::getline(point,dumOne,',')) //using get line read the variable in the file
        {
            dum3 = std::stoi(dumOne);
            if(pa%2 == 0)
            {
                insert.first = dum3; //inser the first character
                g[vx].insert(col,insert); //insert the coloum
                col++;
            }
            else
            {
                insert.second = dum3;
            }
            pa++; //increment the parsing
        }

        pa = 1; //initializng the variables again.
        col = 1;
        vx ++;

    }

    int i = 0;
    while(i<vx) //while loop to get the lenght of the function
    {
        for(int j= 1; j <= g[i].getLength(); j++)
        {
            if(g[i].getEntry(j).second > vx-1)
                vx++;
        }
            i++; //increment each time
    }

    HeapPriorityQueue<std::pair<int,int> > q; //Essentially this is the sueudo code given my the prof
    int a[vx]; //declaring all the variables
    int c = vx;
    int vert;
    int weight;

    std::pair<int,int> t2; //declaring all the temporary variables
    std::pair<int,int> t1;


    int v= 0; //initalizing v for the loop
    while(v<c)
    {
       a[v] = 888888888; //genrate the random number to check
       v++;
    }

    q.add(std::pair<int,int>(0,0)); //calls the add function
    a[0] = 0;

    while(!q.isEmpty()) //while loop to check if empty
    {
        t1 = q.peek(); //temp var is set to peek
        q.remove(); //removes certain from the q

        if(t1.first < a[t1.second]) //checks to see if the temp1 or temp
        {
            a[t1.second] = t1.first; //displays the temp
        }

        for(int x = 1; x <= g[t1.second].getLength(); x++){ //for loop for the getting the vertex
            t2 = g[t1.second].getEntry(x);                  //and weight
            weight = t2.first;
            vert = t2.second;

            if (a[vert] > a[t1.second] + weight){
                a[vert] = a[t1.second] + weight;
                q.add(std::make_pair(a[vert],vert)); //calls the add function with pairs and vetex
            }
        }
    }

    int m= 0; //while loop to the check its not the random contion
    while(m<vx)
    {
        if(a[m] == 888888888)
        {
            a[m] = -1;
        }
        m++;
    }

    std::ofstream outputFile("weight.csv"); //declaring the name and output file


    for(int k = 0; k < c-1; k++)  //This forloop outputs the weights
    {
       outputFile << a[k] << ','; //outputing from the array
    }

    outputFile << a[vx-1]; //ouputing

    return 0;

}


