#include "variablesFromCoordinates.h"

#include "TMath.h"
#include "Math/Vector3D.h"
#include "Math/VectorUtil.h"

float pTRelFromCoordinates(const float& pT1, const float& eta1, const float& phi1,
                           const float& pT2, const float& eta2, const float& phi2)
{
  using ROOT::Math::RhoEtaPhiVector;

  RhoEtaPhiVector vector1(pT1, eta1, phi1);
  RhoEtaPhiVector vector2(pT2, eta2, phi2);

  return ROOT::Math::VectorUtil::Perp(vector1, vector2);
}
 
float deltaRFromCoordinates(const float& pT1, const float& eta1, const float& phi1,
                            const float& pT2, const float& eta2, const float& phi2)
{
  using ROOT::Math::RhoEtaPhiVector;

  RhoEtaPhiVector vector1(pT1, eta1, phi1);
  RhoEtaPhiVector vector2(pT2, eta2, phi2);

  return ROOT::Math::VectorUtil::DeltaR(vector1, vector2);
}

float deltaPhiFromCoordinates(const float& phi1, const float& phi2)
{
  float dPhi = phi1 - phi2;
  if(dPhi > TMath::Pi()) dPhi -= TMath::TwoPi();
  if(dPhi <= -TMath::Pi()) dPhi += TMath::TwoPi();

  return dPhi;
}
