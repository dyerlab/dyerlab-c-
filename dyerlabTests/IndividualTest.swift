//
//  IndividualTest.swift
//  DLabGeneticsTests
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import XCTest
import CoreLocation
@testable import dyerlab


class IndividualTest: XCTestCase {

    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

    func testEmpty() {
        let theInd = Individual()
        
        XCTAssertNil(theInd.getLatitude())
        XCTAssertNil(theInd.getLongitude())
        XCTAssertEqual(theInd.getStrata(key: "Bob"), "")
        XCTAssertEqual(theInd.getExternal(key: "Bob"), 0.0)
        XCTAssertEqual(theInd.getLocus(key: "Bob"), Locus())
        
        XCTAssertEqual(theInd.keys().count, 0)
    }
    
    func testFull() {
        let theInd = Individual()
        
        theInd.strata["Population"] = "First Population"
        theInd.strata["Region"] = "Region One"
        theInd.location = CLLocationCoordinate2DMake(37.533333, -77.466667 )
        theInd.external["Altitude"] = 37.3
        theInd.loci["PGI"] = Locus( alleles: ["1","5"] )
        theInd.loci["LAP"] = Locus( alleles: ["3","7"] )
        
        XCTAssertEqual( theInd.keys().count, 7 )
        XCTAssertEqual(theInd.getLatitude()!, 37.533333, accuracy: 0.001)
        XCTAssertEqual(theInd.getLongitude()!, -77.466667, accuracy: 0.001)
        XCTAssertEqual(theInd.external["Altitude"], 37.3 )
        XCTAssertNil( theInd.external["Bob"] )
        XCTAssertEqual(theInd.strata["Population"], "First Population")
        XCTAssertEqual(theInd.strata["Region"], "Region One")
        XCTAssertNil( theInd.strata["Bob"] )
        XCTAssertNil( theInd.loci["PGM"])
        XCTAssertEqual( theInd.loci["PGI"], Locus(alleles:[ "1","5"]))
        XCTAssertEqual( theInd.loci["LAP"], Locus(alleles: ["3","7"]))
        
        XCTAssertEqual( theInd.dataTypeForKey(key: "Altitude"), IndividualDataType.IndividualDataExternal )
        XCTAssertEqual( theInd.dataTypeForKey(key: "Region"), IndividualDataType.IndividualDataStratum )
        XCTAssertEqual( theInd.dataTypeForKey(key: "LAP"), IndividualDataType.IndividualDataLocus )
        XCTAssertEqual( theInd.dataTypeForKey(key: "Bob"), IndividualDataType.IndividualDataUnknown )
        
        
    }
}
