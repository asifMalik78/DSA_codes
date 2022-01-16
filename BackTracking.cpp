// -----> RAT IN MAZE PROBLEM USIN BACKTRACKING

// #include <iostream>
// using namespace std;
// bool ratMaze(char maze[10][10] , int soln[][10] , int i , int j , int m , int n ){
//     if(i==m || j==n){
//         soln[i][j]=1;
//         for(int i=0;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 cout << soln[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         return true ;
//     }
//     if(i>m || j>n){
//         return false;
//     }
//     if(maze[i][j]=='X'){
//         return false;
//     }
//     soln[i][j]=1;
//     bool rightSuccess=ratMaze(maze , soln , i , j+1 , m , n);
//     bool downSuccess=ratMaze(maze , soln , i+1 , j , n , m);
//     soln[i][j]=0;
//     if(rightSuccess || downSuccess){
//         return true;
//     }
//     return false;
// }
// int main() {
//     char maze[10][10]={"0000" , "00X0" , "000X" , "0X00"};
//     int soln[10][10]={0};
//     int m=4;
//     int n=4;
//     bool ans=ratMaze(maze , soln , 0 , 0 , m-1 , n-1);
//     if(ans==false){
//         cout << "Path doesn't exists ! " ;
//     }
// }



// #include<iostream>
// using namespace std;
// bool ratMaze(char maze[][1005] , int out[][1005] , int i , int j , int n , int m){
//     if(i==n && j==m){
//         out[i][j]=1;
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 cout << out[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         return true;
//     }
//     if(i>n || j>m){
//         return false;
//     }
//     if(maze[i][j]=='X'){
//         return false;
//     }
    
//     out[i][j]=1;
//     bool right=ratMaze(maze , out , i , j+1 , n , m);
//     if(right){
//         return true;
//     }
//     bool down=ratMaze(maze , out , i+1 , j , n , m);
//     if(down){
//         return true;
//     }
//     out[i][j]=0;
//     return false;

// }
// int main() {
    
//     int n,m;
//     cin>>n>>m;
//     char maze[1005][1005];
//     int output[1005][1005]={0};
//     for(int i=0;i<n;i++)
//     {
//       for(int j=0;j<m;j++)
//       {
//         cin>>maze[i][j];
//       }
//     }
//     ratMaze(maze , output , 0 , 0 , n-1 , m-1);
//     return 0;
// }



// ------>  N-QUEEN PROBLEM USING BACKTRACING  (T C => N^N) OPTIMIZED APPROACH 
//         CAN BE USED BY USING BITSET TECHNIQUE WHICH IS O(1) BY CHANGING ISSAFE FN; AND TOTAL TC WILL BE 1/N OF PREVIOUS COMPLEXITY;
// #include <iostream>
// using namespace std;
// bool isSafe(int board[][100] , int i , int j , int n){
//     for(int row=0;row<n;row++){
//         if(board[row][j]==1){
//             return false;
//         }
//     }
//     int x=i;
//     int y=j;
//     while(x>=0 && y>=0){
//         if(board[x][y]==1){
//             return false;
//         }
//         x--;
//         y--;
//     }
//     x=i;
//     y=j;
//     while(x>=0 && y<n){
//         if(board[x][y]==1){
//             return false;
//         }
//         x--;
//         y++;
//     }


//     return true;
// }
// bool nQueen(int board[][100] , int i , int n){
//     if(i==n){
//        for(int r=0;r<n;r++){
//            for(int c=0;c<n;c++){
//                if(board[r][c]==1){
//                    cout << "Q ";
//                }
//                else{
//                    cout << "- ";
//                }
//            }
//            cout << endl;
//        }
//        return true;
//     }
//     for(int j=0;j<n;j++){

//         if(isSafe(board , i , j , n)){
//             board[i][j]=1;
//             bool rakhPaye=nQueen(board , i+1 , n);
//             if(rakhPaye){
//                 return true;
//             }
//             board[i][j]=0;
//         }
//     }
//     return false;
// }
// int main() {
//    int n;
//    cin >> n;
//    int board[100][100]={0};
//    bool ans=nQueen(board , 0 , n);
// }




// OPTIMIZED 1
// #include <iostream>
// #include <bitset>
// using namespace std;
// bitset<30> col , d1 , d2;
// void nQueenOptimized(int r , int n , int &ans , int b[][100]){
//     if(r==n){
//         ans++;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout << b[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         return;
//     }

//     for(int c=0 ; c<n ; c++){
//         if(!col[c] && !d1[r+c] && !d2[r-c+n-1]){
//             col[c]=d1[r+c]=d2[r-c+n-1]=b[r][c]=1;
//             nQueenOptimized(r+1 , n , ans , b);
//             col[c]=d1[r+c]=d2[r-c+n-1]=b[r][c]=0;
//         }
//     }

// }
// int main() {
//     int n;
//     cin >> n;
//     int ans=0;
//     int board[100][100];
//     nQueenOptimized(0 , n , ans , board);
//     cout << ans << endl;
// }



// OPTIMIZED 2
// #include <iostream>
// using namespace std;
// int n , ans=0 , DONE;
// void nQueenOptimized(int rowMask , int ld , int rd){
//     if(rowMask==DONE){
//        ans++;
//        return;
//     }
//     int safe=DONE &(~(rowMask | ld | rd));
//     while(safe){
//         int p=safe & (-safe);
//         safe-=p;
//         nQueenOptimized(rowMask|p , (ld|p) << 1 , (rd|p) >> 1);
//     }
//     return ;
// }
// int main() {
//     cin >> n;
//     DONE=(1 << n)-1;
//     nQueenOptimized(0 , 0 , 0);
//     cout << ans << endl;  
// }




// -----> SODUKO SOLVER
//        QUESTION :--

//          {5,3,0,0,7,0,0,0,0},
//          {6,0,0,1,9,5,0,0,0},
//          {0,9,8,0,0,0,0,6,0},
//          {8,0,0,0,6,0,0,0,3},
//          {4,0,0,8,0,3,0,0,1},
//          {7,0,0,0,2,0,0,0,6},
//          {0,6,0,0,0,0,2,8,0},
//          {0,0,0,4,1,9,0,0,5},
//          {0,0,0,0,8,0,0,7,9},


// -------->  ANSWER :--
//             5 3 4 6 7 8 9 1 2 
//             6 7 2 1 9 5 3 4 8 
//             1 9 8 3 4 2 5 6 7 
//             8 5 9 7 6 1 4 2 3 
//             4 2 6 8 5 3 7 9 1 
//             7 1 3 9 2 4 8 5 6 
//             9 6 1 5 3 7 2 8 4 
//             2 8 7 4 1 9 6 3 5 
//             3 4 5 2 8 6 1 7 9 



#include <iostream>
#include <cmath>
using namespace std;
bool canPlace(int matrix[][9] , int i , int j , int n , int number){
    for(int x=0 ; x<n ; x++){
        if(matrix[x][j]==number || matrix[i][x]==number){
            return false;
        }
    }
        int rn=sqrt(n);
        int sx=(i/rn)*rn;
        int sy=(j/rn)*rn;
        for(int r=sx ; r<sx+rn ; r++){
            for(int c=sy ; c<sy+rn ; c++){
                if(matrix[r][c]==number){
                    return false;
                }
            }
        }
        return true;

}
bool sadukoSolver(int saduko[][9] , int i , int j , int n){
    if(i==n){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               cout << saduko[i][j]  << " ";
           }
           cout << endl;
       }
       return true;
    }
    if(j==n){
        return sadukoSolver(saduko , i+1 , 0 , n);
    }
    if(saduko[i][j]!=0){
        return sadukoSolver(saduko , i , j+1 , n);
    }
    
    for(int number=1 ; number<=n ; number++){
        if(canPlace(saduko , i , j , n , number)){
            saduko[i][j]=number;

            bool sahiHai=sadukoSolver(saduko , i , j , n);
            if(sahiHai){
                return true;
            }
        }
    }
    saduko[i][j]=0;
    return false;

}
int main() {
    int matrix[9][9]={
         {5,3,0,0,7,0,0,0,0},
         {6,0,0,1,9,5,0,0,0},
         {0,9,8,0,0,0,0,6,0},
         {8,0,0,0,6,0,0,0,3},
         {4,0,0,8,0,3,0,0,1},
         {7,0,0,0,2,0,0,0,6},
         {0,6,0,0,0,0,2,8,0},
         {0,0,0,4,1,9,0,0,5},
         {0,0,0,0,8,0,0,7,9},
    };
    sadukoSolver(matrix , 0 , 0 , 9);
    
}
