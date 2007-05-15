#include "SimMuon/CSCDigitizer/src/CSCStripConditions.h"
#include "CLHEP/Random/RandGaussQ.h"

CSCStripConditions::CSCStripConditions()
  : theNoisifier(0),
    theRandGaussQ(0)
 {}


CSCStripConditions::~CSCStripConditions() 
{
  delete theNoisifier;
  delete theRandGaussQ;
}


void CSCStripConditions::setRandomEngine(CLHEP::HepRandomEngine& engine)
{
  theRandGaussQ = new RandGaussQ(engine);
}


float CSCStripConditions::smearedGain(const CSCDetId & detId, int channel) const
{
  return theRandGaussQ->fire( gain(detId, channel), gainSigma(detId, channel) );
}


void CSCStripConditions::noisify(const CSCDetId & detId, CSCAnalogSignal & signal)
{
  const int nScaBins = 8;
  const float scaBinSize = 50.;
  int channel = signal.getElement();
  std::vector<float> binValues(nScaBins, 0.);
  // use a temporary signal, in case we have to rebin
  CSCAnalogSignal tmpSignal(channel, scaBinSize, binValues,
                            0., signal.getTimeOffset());

  fetchNoisifier(detId, channel );
  theNoisifier->noisify(tmpSignal);
  // noise matrix is in ADC counts. onvert to fC
  tmpSignal *= 1./gain(detId, channel);
  signal.superimpose(tmpSignal);
}

 
float CSCStripConditions::analogNoise(const CSCDetId & detId, int channel) const
{
  return sqrt(2) * pedestalSigma(detId, channel) / gain(detId, channel);
}


