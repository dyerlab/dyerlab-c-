//
//  Population.swift
//  DLabGenetics
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation

class Population {
    var individuals: [Individual]
    var numIndividuals : Int {
        get {
            return self.individuals.count
        }
    }
    
    init() {
        self.individuals = [Individual]()
    }
    
    func addIndividual( theInd: Individual ) {
        self.individuals.append(theInd)
    }
    
    func getAlleleFrequencies( locusName: String ) -> AlleleFrequencies {
        let freqs = AlleleFrequencies()
        for ind in self.individuals {
            freqs.addLocus(loc: ind.getLocus(key: locusName ) )
        }
        return freqs
    }
}
