#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    // take in number of test cases, error check
    int numCases;
    cin >> numCases;
    if( numCases > 10 || numCases < 1 ) {
        cout << "Error with input." << endl;
        return 1;
    }

    // take in test cases
    vector< string > results;
    for( int i = 0; i < numCases; i++ ) {
        
        vector< int > data;
        int numElements;
        cin >> numElements;
        int totalSum = 0;
        for( int i = 0; i < numElements; i++ ) {
            int element;
            cin >> element;
            data.push_back( element );
            totalSum += element;
        } 

        // run test on this array
        int leftSum = 0;
        int rightSum = totalSum;
        int flag = 1;
        for( vector< int >::iterator it = data.begin(); it != data.end(); it++ ) {
            if( it == data.begin() ) {
                leftSum = 0;
            } else {
                leftSum = leftSum + *( it - 1 );
            }
            rightSum -= ( *it );                
            
            if( leftSum == rightSum ) {
                results.push_back( "YES" );
                flag = 0;
            }
        }
        if( flag == 1 ) results.push_back( "NO" );
        
    } // for
    
    // print results
    for( vector< string >:: iterator it = results.begin(); it != results.end(); it++ ) {
        cout << (*it) << endl;
    } 
}
