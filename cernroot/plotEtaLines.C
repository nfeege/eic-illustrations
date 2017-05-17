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

void plotEtaLines()
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

  /* Frame histogram */
  float frame_zmin = -2.5;
  float frame_zmax = 2.5;
  float frame_rmin = 0;
  float frame_rmax = 2.5;

  TH1F* hframe = new TH1F("hframe","",100,frame_zmin,frame_zmax);
  hframe->GetYaxis()->SetRangeUser(frame_rmin,frame_rmax);
  hframe->SetLineColor(0);
  hframe->GetXaxis()->SetTitle("z [m]");
  hframe->GetYaxis()->SetTitle("r [m]");
  hframe->GetYaxis()->SetTitleOffset(0.7);

  /* Detector box */
  TBox *detbox = new TBox( -2, 0, 2, 2 );
  detbox->SetFillColor(kGray);

  vector<float> v_etas;
  v_etas.push_back(1.0);
  v_etas.push_back(-1.0);
  //  v_etas.push_back(-2.0);
  //  v_etas.push_back(-3.0);

  /* Draw canvas ePHENIX*/
  TCanvas *c_etas = new TCanvas();
  hframe->Draw();
  detbox->Draw("fsame");
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
      l_eta->SetLineColor(kRed);
      l_eta->SetLineWidth(5);
      l_eta->Draw("same");
    }

  gPad->RedrawAxis();

  c_etas->Print("detectorGeometry_etas_v0.png");
  c_etas->Print("detectorGeometry_etas_v0.eps");

  return;
}
