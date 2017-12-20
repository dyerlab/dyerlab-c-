//
//  GeneticFileIOTest.swift
//  
//
//  Created by Rodney Dyer on 12/20/17.
//

import XCTest
import CoreLocation
@testable import dyerlab

class GeneticFileIOTest: XCTestCase {

    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

    func testLoadAraptus() {
        let thePop = loadArapatData()
        
        XCTAssert( thePop.numIndividuals > 0 )
        XCTAssert( thePop.numIndividuals == 363)

        // Species,Cluster,Population,ID,Latitude,Longitude,LTRS,WNT,EN,EF,ZMP,AML,ATPS,MP20
        // Peninsula,NBP-C,88,88_11A,29.32541,-114.29353,01:01,,02:04,01:02,,,09:09,07:07
        let theInd = thePop.individuals[0]
        
        print("The Individual at location zero")
        print("\(theInd)")
        
        let indKeys = Set<String>(theInd.keys())
        let prefKeys = Set<String>(["Species","Cluster","Population","ID","Latitude","Longitude","LTRS","WNT","EN","EF","ZMP","AML","ATPS","MP20"])
        XCTAssert( indKeys == prefKeys )
        
        XCTAssert( theInd.getStrata(key: "Population") == "88")
        XCTAssert( theInd.getStrata(key: "Cluster") == "NBP-C")
        XCTAssert( theInd.getStrata(key: "Species") == "Peninsula")
        XCTAssert( theInd.getLocus(key: "LTRS") == Locus(alleles: ["01","01"]))
        XCTAssert( theInd.getLocus(key: "AML") == Locus() )
        XCTAssert( theInd.location!.latitude == 29.32541)
        XCTAssert( theInd.location!.longitude == -114.29353 )
        
    }
    
}
