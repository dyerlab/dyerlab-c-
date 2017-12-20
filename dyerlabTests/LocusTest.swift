//
//  LocusTest.swift
//  DLabGeneticsTests
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import XCTest
@testable import dyerlab


class LocusTest: XCTestCase {
    
    override func setUp() {
        super.setUp()
    }
    
    override func tearDown() {
        super.tearDown()
    }
    
    func testEmpty() {
        let theLoc: Locus
        theLoc = Locus()
        
        XCTAssertEqual( theLoc.ploidy, 0 )
        XCTAssertFalse( theLoc.isHeterozygote )
        
    }
    
    func testHaploid() {
        let theLoc: Locus
        let alleles = ["A"]
        theLoc = Locus(alleles: alleles)
        
        XCTAssertEqual( theLoc.ploidy, 1 )
        XCTAssertFalse( theLoc.isHeterozygote )
    }
    
    func testDiploid() {
        let theLocHet = Locus( alleles:["A","B"] )
        let theLocHom = Locus( alleles:["A","A"] )
        
        XCTAssertEqual( theLocHet.ploidy, 2 )
        XCTAssertEqual( theLocHom.ploidy, 2 )
        XCTAssertTrue( theLocHet.isHeterozygote )
        XCTAssertFalse( theLocHom.isHeterozygote )
    }
    
    func testLocusEquatable() {
        let loc1 = Locus( alleles: ["A","B"] )
        let loc2 = Locus( alleles: ["A","B"] )
        let loc3 = Locus( alleles: ["A","C"] )
        let loc4 = Locus()
        
        XCTAssertTrue( loc1 == loc2 )
        XCTAssertFalse( loc1 == loc3 )
        XCTAssertTrue( loc1 != loc3 )
        XCTAssertFalse( loc1 != loc2 )
        XCTAssertFalse( loc1 == loc4 )
        XCTAssertTrue( loc1 != loc4 )
    }
    
    
    func testLocusToVector() {
        let loc1 = Locus( alleles: ["A","B"])
        let loc2 = Locus( alleles: ["B","C"])
        let loc3 = Locus( alleles: ["A","A"])
        let alleles = ["A","B","C"]
        
        let v1 = loc1.toVector(alleles: alleles)
        let v2 = loc2.toVector(alleles: alleles)
        let v3 = loc3.toVector(alleles: alleles)
        XCTAssertEqual( v1, [1.0,1.0,0.0] )
        XCTAssertEqual( v2, [0.0,1.0,1.0] )
        XCTAssertEqual( v3, [2.0,0.0,0.0] )
    }

}
