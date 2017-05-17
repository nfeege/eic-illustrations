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

/* 
 * Details about chosen geometry in this macro:
 * Magnet: Babar coil and cryostat CAD drawing ephenix_v1
 * Barrel: sPhenix MIE 2015 = CAD drawing ephenix_v1
 * EIC detectors: ephenix_v1 CAD drawing (HCAL) + ECAL and PID detectors and GEM from LOI 2014 ("babar_v11")
 *
 */
void show_detectorGeometry_v3()
{
  gStyle->SetOptStat(0);

  double pad_h = 500;
  double pad_w = 1000;

  double pad_mtop = 10. / pad_h;
  double pad_mbottom = 100. / pad_h;


  double pad_mleft = 200. / pad_w;
  double pad_mright = 20. / pad_w;

  gStyle->SetCanvasDefH(pad_h);
  gStyle->SetCanvasDefW(pad_w);

  //  gStyle->SetPadMargin( pad_mleft, pad_mright, pad_mbottom, pad_mtop );
  gStyle->SetPadLeftMargin(pad_mleft);
  gStyle->SetPadRightMargin(pad_mright);
  gStyle->SetPadTopMargin(pad_mtop);
  gStyle->SetPadBottomMargin(pad_mbottom);

//  gStyle->SetPadLeftMargin(0.1);
//  gStyle->SetPadRightMargin(0.02);
//  gStyle->SetPadTopMargin(0.01);
//  gStyle->SetPadBottomMargin(0.15);

  /* Frame histogram */
  float frame_zmin = -4;
  float frame_zmax = 5;
  float frame_rmin = 0;
  float frame_rmax = 4.5;

  TH1F* hframe = new TH1F("hframe","",100,frame_zmin,frame_zmax);
  hframe->GetYaxis()->SetRangeUser(frame_rmin,frame_rmax);
  hframe->SetLineColor(0);
  hframe->GetXaxis()->SetTitle("z [m]");
  hframe->GetYaxis()->SetTitle("r [m]");
  hframe->GetYaxis()->SetTitleOffset(0.6);

  vector<float> v_etas;
//  v_etas.push_back(1.0);
//  v_etas.push_back(2.0);
//  v_etas.push_back(4.0);

  v_etas.push_back(1.1);
  v_etas.push_back(1.15);
  v_etas.push_back(1.2);
  //v_etas.push_back(1.3);
  v_etas.push_back(1.45);
  //  v_etas.push_back(1.5);
  //  v_etas.push_back(-1.0);
  v_etas.push_back(-1.2);
  //  v_etas.push_back(2.0);
  //  v_etas.push_back(-2.0);
  v_etas.push_back(4.0);
  v_etas.push_back(5.0);
  v_etas.push_back(-4.5);

  /* HCAL barrel */
  const int c_hcal_n = 9;
  Double_t c_hcal_z[c_hcal_n] = {3.1581,
			  3.1581,
			  -3.1581,
			  -3.1581,
			  -1.5420,
			  -1.4434,
			  1.4434,
			  1.5420,
			  3.1581};
			  
  Double_t c_hcal_r[c_hcal_n] = {1.9500,
			  2.6350,
			  2.6350,
			  1.9500,
			  1.9500,
			  1.8200,
			  1.8200,
			  1.9500,
			  1.9500};

  TPolyLine *c_hcal = new TPolyLine(c_hcal_n,c_hcal_z,c_hcal_r);
  c_hcal->SetFillColor(38);
  c_hcal->SetLineColor(2);
  c_hcal->SetLineWidth(4);

  /* Inner HCAL barrel */
  const int c_hcal_inner_n = 5;
  Double_t c_hcal_inner_z[c_hcal_inner_n] = {2.17500,
				 2.17500,
				 -2.17500,
				 -2.17500,
				 2.17500};

//  /* ALTERNATE inner z */
//  Double_t c_hcal_inner_z[c_hcal_inner_n] = {0.85*1.8300,
//				 0.85*1.82998,
//				 0.85*-1.82998,
//				 0.85*-1.82998,
//				 0.85*1.82998};
			  
  Double_t c_hcal_inner_r[c_hcal_inner_n] = {1.3600,
				 1.1350,
				 1.1350,
				 1.3600,
				 1.3600};

  TPolyLine *c_hcal_inner = new TPolyLine(c_hcal_inner_n,c_hcal_inner_z,c_hcal_inner_r);
  c_hcal_inner->SetFillColor(kOrange-5);
  c_hcal_inner->SetLineColor(2);
  c_hcal_inner->SetLineWidth(4);


  /* ECAL barrel */
  const int c_ecal_n = 5;
  Double_t c_ecal_z[c_ecal_n] = {1.4426,
				 1.4426,
				 -1.4426,
				 -1.4426,
				 1.4426};
			  
  Double_t c_ecal_r[c_ecal_n] = {0.9500,
				 1.1350,
				 1.1350,
				 0.9500,
				 0.9500};

  TPolyLine *c_ecal = new TPolyLine(c_ecal_n,c_ecal_z,c_ecal_r);
  c_ecal->SetFillColor(kBlue-1);
  c_ecal->SetLineColor(2);
  c_ecal->SetLineWidth(4);


  /* ESide Door */
  const int e_door_n = 5;
  Double_t e_door_z[e_door_n] = {-3.6081,
				 -3.6081,
				 -3.3081,
				 -3.3081,
				 -3.6081};
			  
  Double_t e_door_r[e_door_n] = {2.635,
				 0.950,
				 0.950,
				 2.635,
				 2.635};

  TPolyLine *e_door = new TPolyLine(e_door_n,e_door_z,e_door_r);
  e_door->SetFillColor(38);
  e_door->SetLineColor(2);
  e_door->SetLineWidth(4);


  /* ESide ECAL */
  Double_t e_ecal_z1 = -0.9900;
  Double_t e_ecal_z2 = -0.9900 - 0.1800;
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

  TPolyLine *e_ecal = new TPolyLine(e_ecal_n,e_ecal_z,e_ecal_r);
  e_ecal->SetFillColor(kBlue-1);
  e_ecal->SetLineColor(2);
  e_ecal->SetLineWidth(4);

  cout << "** ESide ECAL **" << endl;
  for ( unsigned k = 0; k < e_ecal_n; k++ )
    cout << k << " " << e_ecal_z[k]*1000 << " " << e_ecal_r[k]*1000 << endl;
  cout << "** --- **" << endl;

  /* HSide ECAL */
  //Double_t h_ecal_dz = 0.170;
  Double_t h_ecal_dz = 0.300;
  Double_t h_ecal_z1 = 3.5000 - h_ecal_dz;
  Double_t h_ecal_z2 = 3.5000;
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

  TPolyLine *h_ecal = new TPolyLine(h_ecal_n,h_ecal_z,h_ecal_r);
  h_ecal->SetFillColor(kBlue-1);
  h_ecal->SetLineColor(2);
  h_ecal->SetLineWidth(4);

  cout << "** HSide ECAL **" << endl;
  for ( unsigned k = 0; k < h_ecal_n; k++ )
    cout << k << " " << h_ecal_z[k]*1000 << " " << h_ecal_r[k]*1000 << endl;
  cout << "** --- **" << endl;


  /* HSide HCAL */
  const int h_hcal_n = 5;
  Double_t h_hcal_z[h_hcal_n] = {3.5000,
				 4.5000,
				 4.5000,
				 3.5000,
				 3.5000};
			  
  Double_t h_hcal_r[h_hcal_n] = {0.0500,
				 0.0500,
				 3.3689,
				 2.6202,
				 0.0050};

  TPolyLine *h_hcal = new TPolyLine(h_hcal_n,h_hcal_z,h_hcal_r);
  h_hcal->SetFillColor(38);
  h_hcal->SetLineColor(2);
  h_hcal->SetLineWidth(4);


  /* HSide Flux Return */
  const int h_fluxreturn_n = 6;
  Double_t h_fluxreturn_z[h_fluxreturn_n] = {3.1901,
					     4.5000,
					     4.5000,
					     3.2694,
					     3.1901,
					     3.1901};
			  

  Double_t h_fluxreturn_r[h_fluxreturn_n] = {2.3882,
					     3.3689,
					     3.5563,
					     2.6350,
					     2.6350,
					     2.3882};

  TPolyLine *h_fluxreturn = new TPolyLine(h_fluxreturn_n,h_fluxreturn_z,h_fluxreturn_r);
  h_fluxreturn->SetFillColor(38);
  h_fluxreturn->SetLineColor(2);
  h_fluxreturn->SetLineWidth(4);


  /* HSide RICH */

  const int h_rich_n = 1000;

  /* HSide RICH - Begin V1*/
  Double_t h_rich_center_z = 0.65000;
  Double_t h_rich_center_r = 0.40000;

  // inner ring
  Double_t h_rich_c1_r = 1.0;
  Double_t h_rich_c1_phimin = -20 / 180. * TMath::Pi();
  Double_t h_rich_c1_phimax= 25 / 180. * TMath::Pi(); // LOI: 61
  Double_t h_rich_c1_dphi = ( h_rich_c1_phimax - h_rich_c1_phimin ) / h_rich_n; 

  // outer ring
  Double_t h_rich_c2_r = 2.0;
  Double_t h_rich_c2_phimin = -8 / 180. * TMath::Pi();
  Double_t h_rich_c2_phimax= 25 / 180. * TMath::Pi(); // LOI: 50
  Double_t h_rich_c2_dphi = ( h_rich_c2_phimax - h_rich_c2_phimin ) / h_rich_n; 
  /* HSide RICH - End V1*/

  /* RICH General part */
  Double_t h_rich_z[h_rich_n*2+1];
  Double_t h_rich_r[h_rich_n*2+1];

  for ( unsigned i = 0; i < h_rich_n*2+1; i++ )
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
      //      cout << i << " (" << h_rich_z[i] << ", " << h_rich_r[i] << ")" << endl;
      cout <<" (" << h_rich_z[i] << ", " << h_rich_r[i] << ") --";
    }

  cout << endl;

  TPolyLine *h_rich = new TPolyLine(h_rich_n*2+1,h_rich_z,h_rich_r);
  h_rich->SetFillColor(kGreen+1);
  h_rich->SetLineColor(kBlack);

  cout << "** HSide RICH **" << endl;
  cout << "inner 1 " << h_rich_z[0]*1000 << " " << h_rich_r[0]*1000 << endl;
  cout << "inner 2 " << h_rich_z[h_rich_n/2-1]*1000 << " " << h_rich_r[h_rich_n/2-1]*1000 << endl;
  cout << "inner 3 " << h_rich_z[h_rich_n-1]*1000 << " " << h_rich_r[h_rich_n-1]*1000 << endl;
  cout << "outer 1 " << h_rich_z[h_rich_n]*1000 << " " << h_rich_r[h_rich_n]*1000 << endl;
  cout << "outer 2 " << h_rich_z[h_rich_n+h_rich_n/2-1]*1000 << " " << h_rich_r[h_rich_n+h_rich_n/2-1]*1000 << endl;
  cout << "outer 3 " << h_rich_z[h_rich_n+h_rich_n-1]*1000 << " " << h_rich_r[h_rich_n+h_rich_n-1]*1000 << endl;
  cout << "** --- **" << endl;


  /* HSide Aerogel */
  const int h_aerogel_n = 5;

  Double_t h_aerogel_d = 0.15;
  Double_t h_aerogel_l = 0.5;
  Double_t h_aerogel_z0 = 2.53;
  Double_t h_aerogel_theta0 = eta2theta( 1.42 ); //~ 35 / 180. * TMath::Pi(); 


  Double_t h_aerogel_z[h_aerogel_n];  
  Double_t h_aerogel_r[h_aerogel_n];  

  h_aerogel_z[0] = h_aerogel_z0;
  h_aerogel_r[0] = h_aerogel_z0 * tan( h_aerogel_theta0 );

  h_aerogel_z[1] = h_aerogel_z[0] + h_aerogel_d * cos( h_aerogel_theta0 );
  h_aerogel_r[1] = h_aerogel_r[0] + h_aerogel_d * sin( h_aerogel_theta0 );

  h_aerogel_z[2] = h_aerogel_z[1] + h_aerogel_l * sin( h_aerogel_theta0 );
  h_aerogel_r[2] = h_aerogel_r[1] - h_aerogel_l * cos( h_aerogel_theta0 );

  h_aerogel_z[3] = h_aerogel_z[2] - h_aerogel_d * cos( h_aerogel_theta0 );
  h_aerogel_r[3] = h_aerogel_r[2] - h_aerogel_d * sin( h_aerogel_theta0 );

  h_aerogel_z[4] = h_aerogel_z[0];
  h_aerogel_r[4] = h_aerogel_r[0];


  cout << "** HSide Aerogel **" << endl;
  cout << "(" << h_aerogel_z[0] << ", " << h_aerogel_r[0] << ") --"
       << "(" << h_aerogel_z[1] << ", " << h_aerogel_r[1] << ") --"
       << "(" << h_aerogel_z[2] << ", " << h_aerogel_r[2] << ") --"
       << "(" << h_aerogel_z[3] << ", " << h_aerogel_r[3] << ") --"
       << "(" << h_aerogel_z[4] << ", " << h_aerogel_r[4] << ")" << endl;
  cout << "** --- **" << endl;


  TPolyLine *h_aerogel = new TPolyLine(h_aerogel_n,h_aerogel_z,h_aerogel_r);
  h_aerogel->SetFillColor(kGreen+1);
  h_aerogel->SetLineColor(2);
  h_aerogel->SetLineWidth(4);


  /* HSide BBC */
  Double_t h_bbc_dz = 0.200;
  Double_t h_bbc_z1 = 3.5000 - h_bbc_dz;
  Double_t h_bbc_z2 = 3.5000;
  Double_t h_bbc_etamin = 4.0;
  Double_t h_bbc_etamax = 5.0;
  Double_t h_bbc_z1_rmax = h_bbc_z1 * tan( eta2theta( h_bbc_etamin ) );
  Double_t h_bbc_z1_rmin = h_bbc_z1 * tan( eta2theta( h_bbc_etamax ) );
  Double_t h_bbc_z2_rmax = h_bbc_z2 * tan( eta2theta( h_bbc_etamin ) );
  Double_t h_bbc_z2_rmin = h_bbc_z2 * tan( eta2theta( h_bbc_etamax ) );


  const int h_bbc_n = 5;
  Double_t h_bbc_z[h_bbc_n] = {h_bbc_z1,
				 h_bbc_z1,
				 h_bbc_z2,
				 h_bbc_z2,
				 h_bbc_z1};
			  
  Double_t h_bbc_r[h_bbc_n] = {h_bbc_z1_rmin,
				 h_bbc_z1_rmax,
				 h_bbc_z2_rmax,
				 h_bbc_z2_rmin,
				 h_bbc_z1_rmin};

  TPolyLine *h_bbc = new TPolyLine(h_bbc_n,h_bbc_z,h_bbc_r);
  h_bbc->SetFillColor(kOrange-5);
  h_bbc->SetLineColor(2);
  h_bbc->SetLineWidth(4);


  /* HSide GEMs */
  TLine *gem_h1 = new TLine( 0.1700,
			     0.0200,
			     0.1700,
			     0.1500);

  TLine *gem_h2 = new TLine( 0.6000,
			     0.0200,
			     0.6000,
			     0.1500);

  TLine *gem_h3 = new TLine( 1.5000,
			     1.5000 * tan( eta2theta( 4 ) ),
			     1.5000,
			     1.5000 * tan( eta2theta( 1.15 ) ));

  TLine *gem_h4 = new TLine( 1.9500,
			     1.9500 * tan( eta2theta( 4 ) ),
			     1.9500,
			     0.45 * 1.9500 * tan( eta2theta( 1.15 ) ));

  TLine *gem_h5 = new TLine( 3.0000,
			     3.0000 * tan( eta2theta( 4 ) ),
			     3.0000,
			     0.45 * 3.0000 * tan( eta2theta( 1.15 ) ));
  TLine *gem_h5b = new TLine( 3.0000,
			      0.45 * 3.0000 * tan( eta2theta( 1.15 ) ),
			      2.5000,
			      2.5000 * tan( eta2theta( 1.15 ) ));


  gem_h1->SetLineColor(kRed);
  gem_h2->SetLineColor(kRed);
  gem_h3->SetLineColor(kRed);
  gem_h4->SetLineColor(kRed);
  gem_h5->SetLineColor(kRed);
  gem_h5b->SetLineColor(kRed);

  /* ESide GEMs */
  TLine *gem_e1 = new TLine( -0.300,
			     0.0200,
			     -0.300,
			     0.1500);

  TLine *gem_e2 = new TLine( -0.550,
			     0.0200,
			     -0.550,
			     0.1500);

  TLine *gem_e3 = new TLine( -0.980,
			     0.0200,
			     -0.980,
			     0.800);


  gem_e1->SetLineColor(kRed);
  gem_e2->SetLineColor(kRed);
  gem_e3->SetLineColor(kRed);


  /* Coil */
  const int coil_n = 5;
  Double_t coil_z[coil_n] = {-1.7450,
			     1.7450,
			     1.7450,
			     -1.7450,
			     -1.7450};
			  

  Double_t coil_r[coil_n] = {1.5189,
			     1.5189,
			     1.4781,
			     1.4781,
			     1.5189};
			  

  TPolyLine *coil = new TPolyLine(coil_n,coil_z,coil_r);
  coil->SetFillColor(kGray+3);
  coil->SetLineColor(2);
  coil->SetLineWidth(4);


  /* Cryostat */
  const int cryostat_n = 9;
  Double_t cryostat_z[cryostat_n] = {-1.9250,
				     -1.9250,
				     -1.6290,
				     -1.6290,
				     1.6290,
				     1.6290,
				     1.9250,
				     1.9250,
				     -1.9250};
			  

  Double_t cryostat_r[cryostat_n] = {1.4200,
				     1.8843,
				     1.8843,
				     1.7800,
				     1.7800,
				     1.8843,
				     1.8843,
				     1.4200,
				     1.4200};
			  

  TPolyLine *cryostat = new TPolyLine(cryostat_n,cryostat_z,cryostat_r);
  cryostat->SetFillColor(28);
  cryostat->SetLineColor(2);
  cryostat->SetLineWidth(4);


  /* Barrel TPC */
  const int c_tpc_n = 5;
  Double_t c_tpc_z[c_tpc_n] = {-0.9500,
			       0.9500,
			       0.9500,
			       -0.9500,
			       -0.9500};
			  
  Double_t c_tpc_r[c_tpc_n] = {0.8000,
			       0.8000,
			       0.1500,
			       0.1500,
			       0.8000};
			  

  TPolyLine *c_tpc = new TPolyLine(c_tpc_n,c_tpc_z,c_tpc_r);
  c_tpc->SetFillColor(kViolet-9);
  c_tpc->SetLineColor(2);
  c_tpc->SetLineWidth(4);

  /* Barrel DIRC */
  const int c_dirc_n = 5;
  Double_t c_dirc_zmax = 1.350;
  Double_t c_dirc_length = 4.9500;

  Double_t c_dirc_z[c_dirc_n] = {c_dirc_zmax - c_dirc_length,
				 c_dirc_zmax,
				 c_dirc_zmax,
				 c_dirc_zmax - c_dirc_length,
				 c_dirc_zmax - c_dirc_length};
			  
  Double_t c_dirc_r[c_dirc_n] = {0.8100,
				 0.8100,
				 0.9100,
				 0.9100,
				 0.8100};
			  

  TPolyLine *c_dirc = new TPolyLine(c_dirc_n,c_dirc_z,c_dirc_r);
  c_dirc->SetFillColor(kGreen+1);
  c_dirc->SetLineColor(2);
  c_dirc->SetLineWidth(4);

  cout << "** Barrel DIRC **" << endl;
  for ( unsigned k = 0; k < c_dirc_n; k++ )
    cout << k << " " << c_dirc_z[k]*1000 << " " << c_dirc_r[k]*1000 << endl;
  cout << "** --- **" << endl;

  /* Draw canvas ePHENIX*/
  TCanvas *c_ephenix = new TCanvas();
  hframe->Draw();

  cryostat->Draw("f,sames");
  coil->Draw("f,sames");

  e_door->Draw("f,sames");
  c_hcal->Draw("f,sames");
  h_hcal->Draw("f,sames");
  h_fluxreturn->Draw("f,sames");

  c_hcal_inner->Draw("f,sames");
  c_ecal->Draw("f,sames");
  c_tpc->Draw("f,sames");
  h_bbc->Draw("f,sames");

  e_ecal->Draw("f,sames");
  c_dirc->Draw("f,sames");
  h_ecal->Draw("f,sames");
  h_rich->Draw("fl,sames");
  h_aerogel->Draw("fl,sames");

  gem_h1->Draw("lsame");
  gem_h2->Draw("lsame");
  gem_h3->Draw("lsame");
  gem_h4->Draw("lsame");
  gem_h5->Draw("lsame");
  gem_h5b->Draw("lsame");

  gem_e1->Draw("lsame");
  gem_e2->Draw("lsame");
  gem_e3->Draw("lsame");

  for ( int idxeta = 0; idxeta < v_etas.size(); idxeta++ )
    {
      float eta = v_etas.at(idxeta);
      float theta1 = eta2theta( eta );
      float z_eta = 0;

      if ( eta > 0 )
	z_eta = frame_zmax;
      else
	z_eta = frame_zmin;

      float r_eta = tan( theta1 ) * z_eta;

      TLine* l_eta = new TLine( 0, 0, z_eta, r_eta );
      l_eta->SetLineColor(kGray+2);
      l_eta->Draw("same");
    }

  gPad->RedrawAxis();

  c_ephenix->Print("detectorGeometry_v3_ePhenix.png");
  c_ephenix->Print("detectorGeometry_v3_ePhenix.eps");

  return;
}
