#include <bits/stdc++.h>
using namespace std; 
  
pair<double, double> find_Centroid(vector<pair<double, double> >& v) 
{ 
    pair<double, double> ans = make_pair( 0, 0 ); 
      
    int n = v.size(); 
    double signedArea = 0; 
      
    // For all vertices 
    for (int i = 0; i < v.size(); i++) { 
          
        double x0 = v[i].first, y0 = v[i].second; 
        double x1 = v[(i + 1) % n].first, y1 =  
                            v[(i + 1) % n].second; 
                              
        // Calculate value of A 
        // using shoelace formula 
        double A = (x0 * y1) - (x1 * y0); 
        signedArea += A; 
          
        // Calculating coordinates of 
        // centroid of polygon 
        ans.first += (x0 + x1) * A; 
        ans.second += (y0 + y1) * A; 
    } 
  
    signedArea *= 0.5; 
    ans.first = (ans.first) / (6 * signedArea); 
    ans.second = (ans.second) / (6 * signedArea); 
  
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    //0 0
    //4 0
//4 2
//0 2

    // Coordinate of the vertices 
    vector<pair<double, double> > vp;
    vp.push_back(make_pair( 0, 0 )); 
    vp.push_back(make_pair( 4, 0 )); 
    vp.push_back(make_pair( 2, 2 ));
    //vp.push_back(make_pair( 4, 2 ));
    //vp.push_back(make_pair( 0, 2 ));
                                 
                                           
    pair<double, double> ans = find_Centroid(vp); 
      
    cout << setprecision(12) << ans.first << " " 
        << ans.second << '\n'; 
  
    return 0; 
}