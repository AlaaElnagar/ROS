/*
*File : Multi dimension kalman_filter design 
*by   :Alaa Elnagar @Robotic software Engineer nanodegree powerd by udacity
*T 	  :+20 101 979 3647
*E    :alaaelngar560@yahoo.com
*/

#include <iostream>
#include <math.h>
#include <tuple>
#include "Core" // Eigen Library
#include "LU"   // Eigen Library

using namespace std;
using namespace Eigen;

float measurements[3] = { 1, 2, 3 };

tuple<MatrixXf, MatrixXf> kalman_filter(MatrixXf x, MatrixXf P, MatrixXf u, MatrixXf F, MatrixXf H, MatrixXf R, MatrixXf I)
{
    for (int n = 0; n < sizeof(measurements) / sizeof(measurements[0]); n++) {

        // Measurement Update
        MatrixXf Z(1, 1);    
        Z << measurements[n];                   /*Actual measurement*/
       
        MatrixXf y(1, 1);
        y << Z - (H * x);                       /*Residual between actual and estimated measurements */
         
        MatrixXf S(1, 1);
        S << H * P * H.transpose() + R;         /*map predicted state into mesurement space*/

        MatrixXf K(2, 1);
        K << P * H.transpose() * S.inverse();   /*kalman gain:average factor changing according to state prediction and measurement update uncertainty */

	    //calculate postorior state and covariance
	    x << x + (K * y);                       /*postorior state */

        P << (I - (K * H)) * P;                 /*postorior covariance */

        // Prediction
        x << (F * x) + u;
        P << F * P * F.transpose();
    }

    return make_tuple(x, P);
}

int main()
{

    MatrixXf x(2, 1);// Initial state (location and velocity) 
    x << 0,
    	 0; 
    MatrixXf P(2, 2);//Initial Uncertainty
    P << 100, 0, 
    	 0, 100; 
    MatrixXf u(2, 1);// External Motion
    u << 0,
    	 0; 
    MatrixXf F(2, 2);//Next State Function
    F << 1, 1,
    	 0, 1; 
    MatrixXf H(1, 2);//Measurement Function
    H << 1,
    	 0; 
    MatrixXf R(1, 1); //Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2);// Identity Matrix
    I << 1, 0,
    	 0, 1; 

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x= " << x << endl;
    cout << "P= " << P << endl;

    return 0;
}