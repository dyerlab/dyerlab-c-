//
//  GeneticFileIO.swift
//  dyerlab
//
//  Created by Rodney Dyer on 12/19/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation
import CoreLocation

func loadArapatData() -> Population {
    let thePop = Population()
    
    if let filepath = Bundle.main.path(forResource: "arapat", ofType: "csv") {
        do {
            let contents = try String(contentsOfFile: filepath )
            let array = contents.components(separatedBy: "\n")
            let headers = array[0].components(separatedBy: ",")
            for i in 1 ..< array.count {
                let vals = array[i].components(separatedBy: ",")
                if vals.count > 1 {
                    let theInd = Individual()
                    
                    theInd.strata[ headers[0] ] = vals[0]
                    theInd.strata[ headers[1] ] = vals[1]
                    theInd.strata[ headers[2] ] = vals[2]
                    theInd.strata[ headers[3] ] = vals[3]
                    
                    if let lat = Double(vals[4]), let lon = Double(vals[5]) {
                        theInd.location = CLLocationCoordinate2DMake(lat, lon)
                    }
                    
                    for i in 6 ... 13 {
                        let theAlleles = Array<String>( vals[i].components(separatedBy: ":").filter { $0 != ""} )
                        if theAlleles.count > 0 {
                            theInd.loci[ headers[i] ] = Locus( alleles: theAlleles )
                        } else {
                            theInd.loci[ headers[i] ] = Locus()
                        }
                    }
                    
                    thePop.addIndividual(theInd: theInd)
                }
            }
        } catch {
            // could not be loaded
            print("Could not load in data file")
        }
    } else {
        print("Could not find file in bundle")
    }
    
    return thePop
}
