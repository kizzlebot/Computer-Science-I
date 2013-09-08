// Arup Guha
// 1/19/2010
// Solution for 2009 World Finals Problem A: Approach
// (Used for 1/23/2010 Team Practice)

// Converted to C on 4/26/2010 for Computer Science I Lecture

#include <stdio.h>

#define MAX_PLANES 8

// Just stores an interval for a plane landing.
struct interval {	
	int start;
	int end;
};

int contains(const struct interval* space, double time);
void convertTime(double t, int* pMin, int* pSec);
double getMax(struct interval* times, int length);
int fact(int n);
void nextPerm(int* perm, int length);
double getMaxTime(int* perm, struct interval* times, int length);
int works(int* perm, struct interval* times, int length, double gap);
int getMaxInterval(struct interval* times, int length);

int main() {
		
    FILE* ifp = fopen("approach.in", "r");
	int planes;
    fscanf(ifp, "%d", &planes);
		
	int i, caseNum = 1;
	while (planes != 0) {
			
	    // Store the data.
	    struct interval times[MAX_PLANES]; 
	    for (i=0; i<planes; i++) 
            fscanf(ifp, "%d%d", &times[i].start, &times[i].end);
			
	    // Output the answer.
	    int min, sec;
        convertTime(getMax(times, planes), &min, &sec);
	    printf("Case %d: %d:%02i\n",caseNum, min, sec);
			
	    caseNum++;
		fscanf(ifp,"%d", &planes);
	} 
	
	fclose(ifp);
    return 0;	
}

// Returns true iff time is within space.	
int contains(const struct interval* space, double time) {
    return space->start-1e-9 <= time && time <= space->end+1e-9;    
}
	
// Takes a time in minutes and converts to the time the question wants.
void convertTime(double t, int* pMin, int* pSec) {
		
    // Did this because my binary search usually returns a time that is a bit lower 
    // than the expected value.
    t += 1e-9;
		
    // Split out the components.
    *pMin = (int)t;
    *pSec = (int)((t-(int)t)*60+0.5);
}
	
// Returns the answer to the question.
double getMax(struct interval* times, int length) {
		
    // Initialize the permutation we are trying.
    int i, perm[MAX_PLANES];
    for (i=0; i<length; i++)
		perm[i] = i;
			
    // Go through each permutation and find the best one.
    double max = 0;
    for (i=0; i<fact(length); i++) {
        double thisscore = getMaxTime(perm, times, length);
		if (thisscore > max)
		    max = thisscore;
		nextPerm(perm, length);
    }
		
    // Return it.
    return max;
}
	
// Returns n!
int fact(int n) {
    int i, ans = 1;
    for (i=2; i<=n; i++)
        ans*= i;
    return ans;
}
	
// Change perm to the next lexicographical permutation.
void nextPerm(int* perm, int length) {
		
    // Find the spot that needs to change.
    int i = length-1;
    while (i>0 && perm[i] < perm[i-1]) i--;
    i--;
		
    // So last perm doesn't cause a problem
    if (i == -1) return;
		
    // Find the spot with which to swap index i.
    int j=length-1;
    while (j>i && perm[j]<perm[i]) j--;
		
    // Swap it.
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;
		
    // reverse from index i+1 to length-1.
    int k,m;
    for (k=i+1,m=length-1; k<(length+i+1)/2; k++,m--) {
		temp = perm[k];
		perm[k] = perm[m];
		perm[m] = temp;
    }
}
	
// Find the max time interval for THIS permutation.
double getMaxTime(int* perm, struct interval* times, int length) {
		
    // Set up our binary search.
    double high = getMaxInterval(times, length);
    double low = 0, mid = (low+high)/2;
		
    // Keep on going until interval is very small.
    while (high-low > 1e-9) {
			
		mid = (low+high)/2;
			
		// Standard binary search.
		if (works(perm,times,length,mid))
		    low = mid;
		else
		    high = mid;
    }
		
    return mid;
}
	
	// Returns true if gap is permissible for THIS permutation.
int works(int* perm, struct interval* times, int length, double gap) {
		
    // First plane lands ASAP.
    double curtime = times[perm[0]].start;
	int i;	
		
    for (i=1; i<length; i++) {
			
		// Find the nearest time the next plane can land.
		double nexttime = curtime+gap;
			
		// Advance this if necessary to the start of the next plane,
		// since more time is allowable.
		if (nexttime < times[perm[i]].start)
		    nexttime = times[perm[i]].start;
				
		// If the plane can't land at this time, this gap doesn't work.
		if (!contains(&times[perm[i]],nexttime))
		    return 0;
		else 
		    curtime = nexttime;
    }
		
	// We made it.
	return 1;
}
	
// Just returns the difference between the first and last times in the
// whole set of intervals.
int getMaxInterval(struct interval* times, int length) {
		
    int min = times[0].start;
    int max = times[0].end;
    int i;
    for (i=1; i<length; i++) {
		if (times[i].start < min)
		    min = times[i].start;
		if (times[i].end > max)
		    max = times[i].end;
    }
    return max-min;
}
