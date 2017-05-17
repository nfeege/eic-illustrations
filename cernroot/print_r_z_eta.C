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

void print_r_z_eta()
{
  /* ESide ECAL */
  Double_t e_ecal_dz =  180.0;
  Double_t e_ecal_z1 = -990.0;
  Double_t e_ecal_z2 = -990.0 - e_ecal_dz;
  Double_t e_ecal_etamin = -1.2;
  Double_t e_ecal_etamax = -4.5;
  Double_t e_ecal_z1_rmax = e_ecal_z1 * tan( eta2theta( e_ecal_etamin ) );
  Double_t e_ecal_z1_rmin = e_ecal_z1 * tan( eta2theta( e_ecal_etamax ) );
  Double_t e_ecal_z2_rmax = e_ecal_z2 * tan( eta2theta( e_ecal_etamin ) );
  Double_t e_ecal_z2_rmin = e_ecal_z2 * tan( eta2theta( e_ecal_etamax ) );

  const int e_ecal_n = 5;
  Double_t e_ecal_z[e_ecal_n] = {e_ecal_z1,
				 e_ecal_z1,
				 e_ecal_z2,
				 e_ecal_z2,
				 e_ecal_z1};
			  
  Double_t e_ecal_r[e_ecal_n] = {e_ecal_z1_rmin,
				 e_ecal_z1_rmax,
				 e_ecal_z2_rmax,
				 e_ecal_z2_rmin,
				 e_ecal_z1_rmin};

  cout << "** ESide ECAL **" << endl;
  for ( unsigned k = 0; k < e_ecal_n; k++ )
    cout << k << " " << e_ecal_z[k] << " " << e_ecal_r[k] << endl;
  cout << "** --- **" << endl;

  /* HSide ECAL */
  Double_t h_ecal_dz = 30.0;
  Double_t h_ecal_z1 = 3500.0 - h_ecal_dz;
  Double_t h_ecal_z2 = 3500.0;
  Double_t h_ecal_etamin = 1.15;
  Double_t h_ecal_etamax = 4.0;
  Double_t h_ecal_z1_rmax = h_ecal_z1 * tan( eta2theta( h_ecal_etamin ) );
  Double_t h_ecal_z1_rmin = h_ecal_z1 * tan( eta2theta( h_ecal_etamax ) );
  Double_t h_ecal_z2_rmax = h_ecal_z2 * tan( eta2theta( h_ecal_etamin ) );
  Double_t h_ecal_z2_rmin = h_ecal_z2 * tan( eta2theta( h_ecal_etamax ) );

  const int h_ecal_n = 5;
  Double_t h_ecal_z[h_ecal_n] = {h_ecal_z1,
				 h_ecal_z1,
				 h_ecal_z2,
				 h_ecal_z2,
				 h_ecal_z1};
			  
  Double_t h_ecal_r[h_ecal_n] = {h_ecal_z1_rmin,
				 h_ecal_z1_rmax,
				 h_ecal_z2_rmax,
				 h_ecal_z2_rmin,
				 h_ecal_z1_rmin};

  cout << "** HSide ECAL **" << endl;
  for ( unsigned k = 0; k < h_ecal_n; k++ )
    cout << k << " " << h_ecal_z[k] << " " << h_ecal_r[k] << endl;
  cout << "** --- **" << endl;


  /* Barrel DIRC */
  const int c_dirc_n = 5;

  Double_t c_dirc_dr = 100.0;
  Double_t c_dirc_r1 = 810.0;
  Double_t c_dirc_r2 = 810.0 + c_dirc_dr;

  Double_t c_dirc_z1 = -4000.0;
  Double_t c_dirc_z2 =   950.0;

  Double_t c_dirc_z[c_dirc_n] = {c_dirc_z1,
				 c_dirc_z2,
				 c_dirc_z2,
				 c_dirc_z1,
				 c_dirc_z1};
			  
  Double_t c_dirc_r[c_dirc_n] = {c_dirc_r1,
				 c_dirc_r1,
				 c_dirc_r2,
				 c_dirc_r2,
				 c_dirc_r1};
			  
  cout << "** Barrel DIRC **" << endl;
  for ( unsigned k = 0; k < c_dirc_n; k++ )
    cout << k << " " << c_dirc_z[k] << " " << c_dirc_r[k] << endl;
  cout << "** --- **" << endl;


  return;
}
