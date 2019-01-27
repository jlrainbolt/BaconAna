#ifndef BACONANA_DATAFORMATS_TELECTRON_HH
#define BACONANA_DATAFORMATS_TELECTRON_HH

#include "BaconAna/DataFormats/interface/BaconAnaDefs.hh"
#include <TObject.h>

namespace baconhep
{
  class TElectron : public TObject
  {
    public:
      TElectron():
      pt(0), eta(0), phi(0), et(0), energy(0),
      scEt(0), scEta(0), scPhi(0), ecalEnergy(0),
      pfPt(0), pfEta(0), pfPhi(0),
      trkIso(-1), ecalIso(-1), hcalIso(-1), hcalDepth1Iso(-1),
      chHadIso(-1), gammaIso(-1), neuHadIso(-1), puIso(-1),
      ecalPFClusIso(-1), hcalPFClusIso(-1),
      puppiChHadIso(-1), puppiGammaIso(-1), puppiNeuHadIso(-1), 
      puppiChHadIsoNoLep(-1), puppiGammaIsoNoLep(-1), puppiNeuHadIsoNoLep(-1), 
      d0(-999.), dz(-999.), sip3d(-999.),
      x(-999.), y(-999.), z(-999.),
      sieie(0), e1x5(0), e2x5(0), e5x5(0), r9(0),
      eoverp(0), hovere(0), fbrem(0),
      dEtaInSeed(0), dEtaIn(0), dPhiIn(0),
      mva2016HZZ(-999.), pass2016HZZwpLoose(0),
      mva2017isoV1(-999.), pass2017isoV1wpLoose(0),
      mva2017noIsoV1(-999.), pass2017noIsoV1wpLoose(0), 
      mva2017isoV2(-999.), pass2017isoV2wpLoose(0), pass2017isoV2wpHZZ(0),
      mva2017noIsoV2(-999.), pass2017noIsoV2wpLoose(0), 
      ecalTrkEnergyPreCorr(0), ecalTrkEnergyPostCorr(0),
      energyScaleUp(0), energyScaleDown(0),
      energySigmaUp(0), energySigmaDown(0),
      regscale(0.),regsmear(0.),
      q(0), isCC(false),
      isConv(false), nMissingHits(0),
      typeBits(0), fiducialBits(0), classification(-999.),
      scID(-1), trkID(-1),
      hltMatchBits(0)
      {}
      ~TElectron(){}
    
      float         pt, eta, phi, et, energy;                   // kinematics
      float         scEt, scEta, scPhi;                         // supercluster kinematics
      float         ecalEnergy;                                 // ECAL energy
      float         pfPt, pfEta, pfPhi;                         // matching PF-candidate kinematics
      float         trkIso, ecalIso, hcalIso, hcalDepth1Iso;    // detector isolation
      float         chHadIso, gammaIso, neuHadIso, puIso;       // PF isolation variables
      float         ecalPFClusIso, hcalPFClusIso;               // PF cluster isolation variables
      float         puppiChHadIso,      puppiGammaIso,      puppiNeuHadIso;  // Puppi Isolation R=0.4
      float         puppiChHadIsoNoLep, puppiGammaIsoNoLep, puppiNeuHadIsoNoLep; // Puppi Isolation R=0.4 no lep
      float         d0, dz, sip3d;                              // impact parameter
      float         x, y, z;                                    // position of innermost (reference) point of best track
      float         sieie, e1x5, e2x5, e5x5, r9;                // shower shape
      float         eoverp;                                     // E/p
      float         hovere;                                     // H/E
      float         fbrem;                                      // brem fraction
      float         dEtaInSeed, dEtaIn, dPhiIn;                 // track-supercluster matching
      float         mva2016HZZ;                                 // MVA value (2016 legacy)
      bool          pass2016HZZwpLoose;                         // bool for loose working point
      float         mva2017isoV1;                               // MVA value (2017v1 with iso)
      bool          pass2017isoV1wpLoose;                       // bool for loose working point
      float         mva2017noIsoV1;                             // MVA value (2017v1 no iso)
      bool          pass2017noIsoV1wpLoose;                     // bool for loose working point
      float         mva2017isoV2;                               // MVA value (2017v2 with iso)
      bool          pass2017isoV2wpLoose, pass2017isoV2wpHZZ;   // bools for loose, HZZ working points
      float         mva2017noIsoV2;                             // MVA value (2017v2 no iso)
      bool          pass2017noIsoV2wpLoose;                     // bool for loose working point
      float         ecalTrkEnergyPreCorr, ecalTrkEnergyPostCorr;// energies for scale/smear correction
      float         energyScaleUp, energyScaleDown;             // scale systematics
      float         energySigmaUp, energySigmaDown;             // smear systematics
      float         regscale,regsmear;                          // Regression scale and smear corrections
      int           q;                                          // charge
      bool          isCC;                                       // isGsfCtfChargeConsistent (3 charge verification)
      bool          isConv;                                     // identified by track fit based conversion finder?
      unsigned int  nMissingHits;                               // number of missing expected inner hits 
      unsigned int  typeBits;                                   // electron type
      unsigned int  fiducialBits;                               // ECAL fiducial region bits
      int           classification;                             // electron classification
      int           scID;                                       // supercluster ID number (unique per event)
      int           trkID;                                      // track ID number (unique per event)
      unsigned int  eleIndex;                                   // unique index identifying the electron
      TriggerObjects hltMatchBits;                              // HLT matches
      
    ClassDef(TElectron,8)
  };

  enum EEleType
  {
    kEcalDriven    = 1,
    kTrackerDriven = 2
  };

  enum EEleId
  {
    kEleMVAMedBit    = 1,
    kEleMVATightBit = 2
  };
}
#endif
