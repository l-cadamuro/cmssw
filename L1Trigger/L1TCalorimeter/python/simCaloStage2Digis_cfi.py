import FWCore.ParameterSet.Config as cms

simCaloStage2Digis = cms.EDProducer(
    "L1TStage2Layer2Producer",
    towerToken = cms.InputTag("layer1EmulatorDigis"),
    firmware = cms.int32(1)
)
