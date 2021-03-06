#include <iostream>

#include "L1Trigger/L1TMuonOverlap/interface/OMTFConfigMaker.h"
#include "L1Trigger/L1TMuonOverlap/interface/OMTFConfiguration.h"
#include "L1Trigger/L1TMuonOverlap/interface/GoldenPattern.h"
#include "L1Trigger/L1TMuonOverlap/interface/XMLConfigReader.h"
#include "L1Trigger/L1TMuonOverlap/interface/OMTFinput.h"
#include "L1Trigger/L1TMuonOverlap/interface/OMTFResult.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

///////////////////////////////////////////////
///////////////////////////////////////////////
OMTFConfigMaker::OMTFConfigMaker(const edm::ParameterSet & theConfig){ 

  std::vector<int> refPhi1D(OMTFConfiguration::nLogicRegions,2*OMTFConfiguration::nPhiBins);
  minRefPhi2D.assign(OMTFConfiguration::nRefLayers,refPhi1D);

  refPhi1D = std::vector<int>(OMTFConfiguration::nLogicRegions,-2*OMTFConfiguration::nPhiBins);
  maxRefPhi2D.assign(OMTFConfiguration::nRefLayers,refPhi1D);

}
///////////////////////////////////////////////
///////////////////////////////////////////////
OMTFConfigMaker::~OMTFConfigMaker(){ }
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillCounts(unsigned int iProcessor,
				 const OMTFinput & aInput){

}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillPhiMaps(unsigned int iProcessor,
				  const OMTFinput & aInput){

  ////Find starting and ending iPhi of each input used for reference hits.
  for(unsigned int iRefLayer=0;iRefLayer<OMTFConfiguration::nRefLayers;++iRefLayer){
    const OMTFinput::vector1D & refLayerHits = aInput.getLayerData(OMTFConfiguration::refToLogicNumber[iRefLayer]);	
    if(!refLayerHits.size()) continue;
    for(unsigned int iInput=0;iInput<OMTFConfiguration::nInputs;++iInput){	
      int phiRef = refLayerHits[iInput];
      unsigned int iRegion = OMTFConfiguration::getRegionNumberFromMap(iInput,iRefLayer,phiRef);       
      if(phiRef>=(int)OMTFConfiguration::nPhiBins) continue;      
      if(phiRef<minRefPhi2D[iRefLayer][iRegion]) minRefPhi2D[iRefLayer][iRegion] = phiRef;      
      if(phiRef>maxRefPhi2D[iRefLayer][iRegion]) maxRefPhi2D[iRefLayer][iRegion] = phiRef;      
    }
  }
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::printPhiMap(std::ostream & out){
  
  out<<"min Phi in each logicRegion (X) in each ref Layer (Y): "<<std::endl; 
  for(unsigned int iRefLayer=0;iRefLayer<OMTFConfiguration::nRefLayers;++iRefLayer){
    for(unsigned int iLogicRegion=0;iLogicRegion<OMTFConfiguration::nLogicRegions;++iLogicRegion){
      out<<"          "<<minRefPhi2D[iRefLayer][iLogicRegion]<<"\t";
    }
    out<<std::endl;
  }
  out<<std::endl; 

  out<<"max Phi in each logicRegion (X) in each ref Layer (Y): "<<std::endl;
  for(unsigned int iRefLayer=0;iRefLayer<OMTFConfiguration::nRefLayers;++iRefLayer){
    for(unsigned int iLogicRegion=0;iLogicRegion<OMTFConfiguration::nLogicRegions;++iLogicRegion){
      out<<"          "<<maxRefPhi2D[iRefLayer][iLogicRegion]<<"\t";
    }
    out<<std::endl;
  }
  out<<std::endl; 

}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::makeConnetionsMap(unsigned int iProcessor,
					const OMTFinput & aInput){

  fillPhiMaps(iProcessor,aInput);
  
  for(unsigned int iRefLayer=0;iRefLayer<OMTFConfiguration::nRefLayers;++iRefLayer){
    const OMTFinput::vector1D & refLayerHits = aInput.getLayerData(OMTFConfiguration::refToLogicNumber[iRefLayer]);    
    if(!refLayerHits.size()) continue;
    //////////////////////
    for(unsigned int iInput=0;iInput<refLayerHits.size();++iInput){
      int phiRef = refLayerHits[iInput];
      unsigned int iRegion = OMTFConfiguration::getRegionNumberFromMap(iInput,iRefLayer,phiRef);     
      if(iRegion>=OMTFConfiguration::nLogicRegions) continue;      
      fillInputRange(iProcessor,iRegion,aInput);
      fillInputRange(iProcessor,iRegion,iRefLayer,iInput);
      ///Always use two hits from a single chamber. 
      ///As we use single muons, the second hit has
      ///to be added by hand.
      if(iInput%2==0) fillInputRange(iProcessor,iRegion,iRefLayer,iInput+1);
    }      
  }
} 
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillInputRange(unsigned int iProcessor,
				   unsigned int iRegion,
				   const OMTFinput & aInput){

  for(unsigned int iLogicLayer=0;iLogicLayer<OMTFConfiguration::nLayers;++iLogicLayer){

    for(unsigned int iInput=0;iInput<14;++iInput){
      bool isHit = aInput.getLayerData(iLogicLayer)[iInput]<(int)OMTFConfiguration::nPhiBins;
      OMTFConfiguration::measurements4D[iProcessor][iRegion][iLogicLayer][iInput]+=isHit;
    }
  }
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillInputRange(unsigned int iProcessor,
				   unsigned int iRegion,
				   unsigned int iRefLayer,
				   unsigned int iInput){

  ++OMTFConfiguration::measurements4Dref[iProcessor][iRegion][iRefLayer][iInput]; 

}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::printConnections(std::ostream & out,
				       unsigned int iProcessor,
				       unsigned int iRegion){

  out<<"iProcessor: "<<iProcessor
     <<" iRegion: "<<iRegion
     <<std::endl;

  out<<"Ref hits"<<std::endl;
  for(unsigned int iLogicLayer=0;iLogicLayer<OMTFConfiguration::nLayers;++iLogicLayer){
    out<<"Logic layer: "<<iLogicLayer<<" Hits: ";
    for(unsigned int iInput=0;iInput<14;++iInput){
      out<<OMTFConfiguration::measurements4Dref[iProcessor][iRegion][iLogicLayer][iInput]<<"\t";
    }
    out<<std::endl;
  }
  /*
  out<<"Measurement hits"<<std::endl;
  for(unsigned int iLogicLayer=0;iLogicLayer<OMTFConfiguration::nLayers;++iLogicLayer){
    out<<"Logic layer: "<<iLogicLayer<<" Hits: ";
    for(unsigned int iInput=0;iInput<14;++iInput){
      out<<OMTFConfiguration::measurements4D[iProcessor][iRegion][iLogicLayer][iInput]<<"\t";
    }
    out<<std::endl;
  }
  */
  out<<std::endl;
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
