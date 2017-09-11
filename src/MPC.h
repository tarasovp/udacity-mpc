#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

const double dt=0.2;
const double Lf = 2.67;


class MPC {
 public:
  MPC();
  double  prevDelta;
  double prevA;
    
  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
    vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs,
                         Eigen::VectorXd constants);
};

#endif /* MPC_H */
