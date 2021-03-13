# Wrestling_Random_Predictor

Notes on wrestler class wr:

int Tid; ///team id   100 through 2400
int id;  ///wrestler id,  int i + Tid...eg.  101, 102..etc
node * wins;                                                  wins and losses BOTH use the node class for the link list.
node * losses;
int wt;  ///weight  mean = 147, std dev = 22;
int wtClass;
double ability; /// mean = 100, std dev = 15;

Goals:

weight is set manually -> wt class
ability is genrated randomly
simulates bout between two wrestlers
include bout scores and teams scores

Weight classes:
99    ///87 is minimum for 99 and 106
106
113
120
126
132
138
145 ///min is 1 pound more than 2 wt class down, 133 = min
152
160
170
182
195
220
285 /// 196 and 285 is max

Team scoring by individual victory type:

if you win by 1-7 points...victory   = 3 team points
              8-14 points  major     = 4 team points
              15-16 points tech fall = 5 team points
              17+          fall      = 6 team points
              or injury or disqual

              example wr1 -> score 118
                      wr2 -> score 109
                diff = 118-109 = 9 points
                        ->major dec 4 team points
