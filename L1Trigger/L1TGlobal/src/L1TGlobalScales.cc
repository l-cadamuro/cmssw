////
/// \class l1t::L1TGlobalScales.cc
///
/// Description: Dump Accessors for L1 GT Result.
///
/// Implementation:
///    
///
/// \author: Brian Winer Ohio State
///
/// 
#include "L1Trigger/L1TGlobal/interface/L1TGlobalScales.h"

#include <iostream>
#include <fstream>
#include <iomanip>



#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/MessageLogger/interface/MessageDrop.h"


// constructor
l1t::L1TGlobalScales::L1TGlobalScales() 
{

 
}

// destructor
l1t::L1TGlobalScales::~L1TGlobalScales() {
 
}

std::string l1t::L1TGlobalScales::getScalesName() const { return m_ScaleSetName;}


void l1t::L1TGlobalScales::setLUT_CalMuEta(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_CalMuEta.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_CalMuEta.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}


void l1t::L1TGlobalScales::setLUT_CalMuPhi(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_CalMuPhi.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_CalMuPhi.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}


void l1t::L1TGlobalScales::setLUT_DeltaEta(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_DeltaEta.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_DeltaEta.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}

void l1t::L1TGlobalScales::setLUT_DeltaPhi(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_DeltaPhi.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_DeltaPhi.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}

void l1t::L1TGlobalScales::setLUT_Pt(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_Pt.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_Pt.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}

void l1t::L1TGlobalScales::setLUT_Cosh(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_Cosh.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_Cosh.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}

void l1t::L1TGlobalScales::setLUT_Cos(std::string lutName, std::vector<long long> lut)
{
     if (m_lut_Cos.count(lutName) != 0) {
        LogTrace("L1TGlobalScales") << "      LUT \"" << lutName
            << "\"already exists in the LUT map- not inserted!" << std::endl;
        return; 
    }
    
    // Insert this LUT into the Table
    m_lut_Cos.insert(std::map<std::string, std::vector<long long>>::value_type(lutName,lut));

    return;

}


long long l1t::L1TGlobalScales::getLUT_CalMuEta(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_CalMuEta.find(lutName)->second.size()) {
     value = m_lut_CalMuEta.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for CalMuEta LUT (" << lutName <<") size = " << m_lut_CalMuEta.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_CalMuPhi(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_CalMuPhi.find(lutName)->second.size()) {
     value = m_lut_CalMuPhi.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for CalMuPhi LUT (" << lutName <<") size = " << m_lut_CalMuPhi.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_DeltaEta(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_DeltaEta.find(lutName)->second.size()) {
     value = m_lut_DeltaEta.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for DeltaEta LUT (" << lutName <<") size = " << m_lut_DeltaEta.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_DeltaPhi(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_DeltaPhi.find(lutName)->second.size()) {
     value = m_lut_DeltaPhi.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for DeltaPhi LUT (" << lutName <<") size = " << m_lut_DeltaPhi.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_Pt(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_Pt.find(lutName)->second.size()) {
     value = m_lut_Pt.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for Pt LUT (" << lutName <<") size = " << m_lut_Pt.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_Cosh(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_Cosh.find(lutName)->second.size()) {
     value = m_lut_Cosh.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for Cosh LUT (" << lutName <<") size = " << m_lut_Cosh.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}

long long l1t::L1TGlobalScales::getLUT_Cos(std::string lutName, int element) const
{
   long long value = 0;
    
   if(element < (int)m_lut_Cos.find(lutName)->second.size()) {
     value = m_lut_Cos.find(lutName)->second.at(element); 
   } else {
     std::cout << "Warning: Element Requested " << element << " too large for Cos LUT (" << lutName <<") size = " << m_lut_Cos.find(lutName)->second.size() << std::endl; 
   } 
   return value;
}


void l1t::L1TGlobalScales::dumpAllLUTs(std::ostream& myCout) const
{

    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_CalMuEta.begin(); itr != m_lut_CalMuEta.end(); itr++) { 
       dumpLUT(myCout,1,itr->first);
    }
 
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_CalMuPhi.begin(); itr != m_lut_CalMuPhi.end(); itr++) { 
       dumpLUT(myCout,2,itr->first);
    }


    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_DeltaEta.begin(); itr != m_lut_DeltaEta.end(); itr++) { 
       dumpLUT(myCout,3,itr->first);
    }


    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_DeltaPhi.begin(); itr != m_lut_DeltaPhi.end(); itr++) { 
       dumpLUT(myCout,4,itr->first);
    }


    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Cosh.begin(); itr != m_lut_Cosh.end(); itr++) { 
       dumpLUT(myCout,5,itr->first);
    }


    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Cos.begin(); itr != m_lut_Cos.end(); itr++) { 
       dumpLUT(myCout,6,itr->first);
    }
   
   
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Pt.begin(); itr != m_lut_Pt.end(); itr++) { 
        dumpLUT(myCout,7,itr->first);
    }
}

void l1t::L1TGlobalScales::dumpLUT(std::ostream& myCout, int LUTtype, std::string name) const
{
    std::vector<long long> dumpV;
    switch(LUTtype) {
       case 1: {
          dumpV = m_lut_CalMuEta.find(name)->second;
          break;
       } 
       case 2: {
          dumpV = m_lut_CalMuPhi.find(name)->second;
          break;
       } 
       case 3: {
          dumpV = m_lut_DeltaEta.find(name)->second;
          break;
       } 
       case 4: {
          dumpV = m_lut_DeltaPhi.find(name)->second;
          break;
       } 
       case 5: {
          dumpV = m_lut_Cosh.find(name)->second;
          break;
       } 
       case 6: {
          dumpV = m_lut_Cos.find(name)->second;
          break;
       } 
       case 7: {
          dumpV = m_lut_Pt.find(name)->second;
          break;
       }                                           
    }
    
    myCout << "=========================================" << std::endl;
    myCout << "   LUT: " << LUTtype << "  Table: " << name << "   Size = " << dumpV.size() << std::endl;
    myCout << "=========================================" << std::endl;
    for(int i=0; i<(int)dumpV.size(); i++) {
      myCout << " Element " << i << " " << dumpV.at(i) << std::endl;
    }
}

void l1t::L1TGlobalScales::print(std::ostream& myCout) const
{

    myCout << "\n  *************  L1T Global Scales ************" << std::endl;
 
 
    myCout << "   Muon Scales: " << std::endl;
    printScale(m_muScales,myCout);
       	       
    myCout << "   EG Scales: "<< std::endl;
    printScale(m_egScales,myCout);	    

    myCout << "   Tau Scales: "<< std::endl;
    printScale(m_tauScales,myCout);
	   
    myCout << "   Jet Scales: "<< std::endl;
    printScale(m_jetScales,myCout);
	   
	   
    myCout << "   HTT Scales: "<< std::endl;
    printScale(m_httScales,myCout);
	   
    myCout << "   ETT Scales: "<< std::endl;
    printScale(m_ettScales,myCout);
	   
    myCout << "   HTM Scales: "<< std::endl;
    printScale(m_htmScales,myCout);
	   
    myCout << "   ETM Scales: "<< std::endl;
    printScale(m_etmScales,myCout);
    
    
    myCout << std::endl;
    myCout << "   LUTs Stored: " << std::endl;
    myCout << " CalMuEta:";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_CalMuEta.begin(); itr != m_lut_CalMuEta.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;

    myCout << " CalMuPhi:";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_CalMuPhi.begin(); itr != m_lut_CalMuPhi.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;    	   	   	   	   	   

    myCout << " DeltaEta:";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_DeltaEta.begin(); itr != m_lut_DeltaEta.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;    	   

    myCout << " DeltaPhi:";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_DeltaPhi.begin(); itr != m_lut_DeltaPhi.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;    	   

    myCout << " Cos:     ";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Cos.begin(); itr != m_lut_Cos.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;    	   

    myCout << " Cosh:    ";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Cosh.begin(); itr != m_lut_Cosh.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;  
    
    myCout << " Pt:      ";
    for (std::map<std::string, std::vector<long long>>::const_iterator itr = m_lut_Pt.begin(); itr != m_lut_Pt.end(); itr++) { 
       myCout << " " << itr->first;
    }
    myCout << std::endl;      
	   
}
void l1t::L1TGlobalScales::printScale(ScaleParameters scale, std::ostream& myCout) const
{

    myCout <<   "    Pt Min   = "  << std::setw(10) << scale.etMin
	   << "      Pt Max   = "  << std::setw(10) << scale.etMax
	   << "      Pt Step  = "  << std::setw(10) << scale.etStep
           << "\n    Phi Min  = "  << std::setw(10) << scale.phiMin
	   << "      Phi Max  = "  << std::setw(10) << scale.phiMax
	   << "      Phi Step = "  << std::setw(10) << scale.phiStep	    
           << "\n    Eta Min  = "  << std::setw(10) << scale.etaMin
	   << "      Eta Max  = "  << std::setw(10) << scale.etaMax
	   << "      Eta Step = "  << std::setw(10) << scale.etaStep 
           << std::endl;

}
