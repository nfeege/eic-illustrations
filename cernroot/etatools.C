double eta2theta(const double eta)
{
  double theta = 2.0 * atan( exp( -1.0 * eta ) );
  return theta;
}

double theta2eta(const double theta)
{
  double eta = -log(tan(theta / 2.));
  return eta;
}

