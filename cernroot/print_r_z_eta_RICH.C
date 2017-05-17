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

void print_r_z_eta_RICH()
{

  /* HSide RICH */

  const int h_rich_n = 3;

  /* HSide RICH - Begin LOI*/
  Double_t h_rich_center_z = 1000.0;
  Double_t h_rich_center_r =  400.0;

  // inner ring
  Double_t h_rich_c1_r = 1000.0;
  Double_t h_rich_c1_phimin = -20 / 180. * TMath::Pi();
  Double_t h_rich_c1_phimax= 61 / 180. * TMath::Pi();
  Double_t h_rich_c1_dphi = ( h_rich_c1_phimax - h_rich_c1_phimin ) / h_rich_n; 

  // outer ring
  Double_t h_rich_c2_r = 2000.0;
  Double_t h_rich_c2_phimin = -8 / 180. * TMath::Pi();
  Double_t h_rich_c2_phimax= 50 / 180. * TMath::Pi();
  Double_t h_rich_c2_dphi = ( h_rich_c2_phimax - h_rich_c2_phimin ) / h_rich_n; 
  /* HSide RICH - End LOI*/


  /* test */
  Double_t h_rich_eta_i = 3.0;
  double test_slope = tan( eta2theta( h_rich_eta_i ) );
  double test_a = ( 1 + test_slope * test_slope );
  double test_b = ( -2.0 * ( h_rich_center_z + test_slope * h_rich_center_r ) );
  double test_c = ( h_rich_center_z * h_rich_center_z + h_rich_center_r * h_rich_center_r - h_rich_c1_r * h_rich_c1_r );
  double xcrossp = -1 * test_b + sqrt( test_b * test_b - 4 * test_a * test_c ) / ( 2.0 * test_a );
  double xcrossm = -1 * test_b - sqrt( test_b * test_b - 4 * test_a * test_c ) / ( 2.0 * test_a );
  double ycrossp = test_slope * xcrossp;
  double ycrossm = test_slope * xcrossm;

  cout << "TEST p = " << xcrossp << " , " << ycrossp << endl;
  cout << "TEST m = " << xcrossm << " , " << ycrossm << endl;

  /* RICH General part */
  Double_t h_rich_z[h_rich_n*2+1];
  Double_t h_rich_r[h_rich_n*2+1];

  for ( unsigned i = 0; i < h_rich_n*2 + 1; i++ )
    {

      // inner ring
      if ( i < h_rich_n )
	       {
		 h_rich_z[i] = h_rich_center_z + h_rich_c1_r * cos( h_rich_c1_phimin + i * h_rich_c1_dphi );
		 h_rich_r[i] = h_rich_center_r + h_rich_c1_r * sin( h_rich_c1_phimin + i * h_rich_c1_dphi );
	       }
      else if ( i >= h_rich_n && i < h_rich_n*2 )
		{
		  h_rich_z[i] = h_rich_center_z + h_rich_c2_r * cos( h_rich_c2_phimax - (i-h_rich_n) * h_rich_c2_dphi );
		  h_rich_r[i] = h_rich_center_r + h_rich_c2_r * sin( h_rich_c2_phimax - (i-h_rich_n) * h_rich_c2_dphi );
		}
      else
	{
	  h_rich_z[i] = h_rich_z[0];
	  h_rich_r[i] = h_rich_r[0];
	}
    }

  cout << "** HSide RICH **" << endl;
  cout << "inner 1 " << h_rich_z[0] << " " << h_rich_r[0] << endl;
  cout << "inner 2 " << h_rich_z[1] << " " << h_rich_r[1] << endl;
  cout << "inner 3 " << h_rich_z[2] << " " << h_rich_r[2] << endl;
  cout << "outer 1 " << h_rich_z[3] << " " << h_rich_r[3] << endl;
  cout << "outer 2 " << h_rich_z[4] << " " << h_rich_r[4] << endl;
  cout << "outer 3 " << h_rich_z[5] << " " << h_rich_r[5] << endl;
  cout << "** --- **" << endl;

  return;
}
