// PROBLEM :- Find approximate Nth root of a number M upto D decimal places

// Solution T.C. O(N * log(M * 10^D)) S.C. O(1) [Binary Search]

// What can be the  lowest possible Nth root -> 1
//      can be the highest possible Nth root -> M

// Do a binary seatch over this range.

// Lets say X be the mid. Find out X^N and compare with M. 
// 	If X^N > M, the Nth root should be smaller, thus search in left search space.
//	Else      , the Nth root should be greater, thus search in right search space.

// When to stop??
// When the (high - low) value becomes less than 10^(-D).
// Why so? Because it is that point when the approximate value is found upto D decimal place.

// What is the answer?
// Both LOW and HIGH can contribute to answer, as we are not looking for a specific answer, but as an approximate answer.


void findApproximateNthRootOfANumberUptoDdecimalPlaces(int NRoot, int number, int decimalPlaces) {

    double low = 1;
    double high = number;
    double esp = 1.0;
    
    for(int i = 0 ; i < decimalPlaces ; i++){
        esp = esp / 10;
    }

    while((high - low) > esp){

        double mid = (low + high) / 2.0;
        double curValue = 1.0;

        for(int i = 0 ; i < NRoot ; i++){
            curValue *= mid;
        }

        if(curValue > number){
            high = mid;
        }else{
            low = mid;
        }


    }

    cout<<low<<" "<<high<<endl;

    return;

}