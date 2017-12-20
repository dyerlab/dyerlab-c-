//
//  AlleleFrequeniesTest.swift
//  DLabGeneticsTests
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import XCTest
@testable import dyerlab

class AlleleFrequeniesTest: XCTestCase {

    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

    func testEmpty() {
        let freqs = AlleleFrequencies()
        
        XCTAssertEqual( freqs.numAlleles, 0 )
        XCTAssertEqual( freqs.frequency(allele: "A"), 0.0 )
        XCTAssertEqual( freqs.Ho(), 0.0 )
        XCTAssertEqual( freqs.He(), 0.0 )
        
    }
    
    func testWithHaploid() {
        let freqs = AlleleFrequencies()
        freqs.addLocus(loc: Locus(alleles:["A"]))
        freqs.addLocus(loc: Locus(alleles:["A"]))
        freqs.addLocus(loc: Locus(alleles:["B"]))
        freqs.addLocus(loc: Locus(alleles:["A"]))
        
        XCTAssertEqual( freqs.frequency( allele: "A" ), 0.75 )
        XCTAssertEqual( freqs.frequency( allele: "B" ), 0.25 )
        XCTAssertEqual( freqs.frequency( allele: "C" ), 0.00 )
        
        XCTAssertEqual( freqs.Ho(), 0.0 )
        let he = 1.0 - ( pow(0.75,2.0) + pow(0.25,2.0) )
        XCTAssertEqual( freqs.He(), he )
    }
    
    func testWithDiploidLoci() {
        let freqs = AlleleFrequencies()
        freqs.addLocus(loc: Locus(alleles:["A","B"]))
        freqs.addLocus(loc: Locus(alleles:["A","A"]))
        freqs.addLocus(loc: Locus(alleles:["A","B"]))
        
        XCTAssertEqual(freqs.frequency(allele: "A"), 4.0/6.0 )
        XCTAssertEqual(freqs.frequency(allele: "B"), 2.0/6.0 )
        XCTAssertEqual(freqs.frequency(allele: "C"), 0.0 )
        
        let ho = 2.0/3.0
        XCTAssertEqual( freqs.Ho(), ho )
        let he = 1.0 - ( pow((4.0/6.0),2.0)  +  pow( (2.0/6.0), 2.0))
        XCTAssertEqual( freqs.He(),  he )
        
    }
    
    
    func testWithPopulation() {
        let thePop = loadArapatData()
        let freqs = AlleleFrequencies()
        freqs.addPopulation(population: thePop, locus: "LTRS")
        
        XCTAssertEqual( freqs.frequency(allele: "01"), 380.0/726 )
        XCTAssertEqual( freqs.frequency(allele: "02"), 346/726.0 )
        XCTAssertEqual( freqs.Ho(), 86/363.0 )
        XCTAssertEqual( freqs.He(), 0.498903, accuracy: 0.00001)
        
    }

}
