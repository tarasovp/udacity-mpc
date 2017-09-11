# Model
As proposed I used kinematic model with 6 variables - x,y,speed,angle,CTE, angle error and with two actuators - steering and throtle. Equation for model I've taken from the course:

```python
x_[t] = x[t-1] + v[t-1] * cos(psi[t-1]) * dt
y_[t] = y[t-1] + v[t-1] * sin(psi[t-1]) * dt
psi_[t] = psi[t-1] + v[t-1] / Lf * delta[t-1] * dt
v_[t] = v[t-1] + a[t-1] * dt
cte[t] = f(x[t-1]) - y[t-1] + v[t-1] * sin(epsi[t-1]) * dt
epsi[t] = psi[t] - psides[t-1] + v[t-1] * delta[t-1] / Lf * dt
```

# Timestep Length and Elapsed Duration (N & dt)

I've taken N=10 and dt=0.2.

We have a trade-off: 
1. if we have small N*dt out model will see only few track ahead and all turns will be a surprise for it. And for bigger speed we have to have larger N*dt 
2. if we have huge N we will have too big computation time
3. if we have to large dt we will have bad resolution picture about part of the road ahead

# Polynomial Fitting and MPC Preprocessing

The preprocessing is to convert coordinates to car cordinate system and converted speed to M/S from MPH. Than I've fitted 3-degree polynom using waypoints

# Model Predictive Control with Latency
The first point I've taken was time after dt == after 0.1second. This helps to "emulate" latency in optimization. 

# The vehicle must successfully drive a lap around the track.
So the venicle is on the track. I've set minimul throttle to 0.3 and added some penality for slow down - so it go quite fast but still on track;)

## video on track included -  fast.mov 
