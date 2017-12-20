//
//  AlleleFrequencies.swift
//  DLabGenetics
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation

class AlleleFrequencies {
    var counts: Dictionary<String,Double>
    var totAlleles: Double
    var numLoci: Double
    var numHets: Double
    var numAlleles: Int {
        get {
            return self.counts.keys.count
        }
    }
    var alleles: [String] {
        get {
            return self.counts.keys.sorted()
        }
    }
    
    init() {
        self.numLoci = 0.0
        self.numHets = 0.0
        self.totAlleles = 0.0
        self.counts = Dictionary<String,Double>()
    }
    
    func addPopulation( population: Population, locus: String ) {
        for ind in population.individuals {
            self.addLocus(loc: ind.getLocus(key: locus))
        }
    }
    
    func addLocus( loc: Locus ){
        
        if loc.ploidy > 1 {
            numLoci += 1.0
        }
        
        if loc.isHeterozygote {
            self.numHets += 1.0
        }
        
        for allele in loc.alleles {
            let curCount = self.counts[allele] ?? 0.0
            self.counts[ allele ] = (1.0 + curCount)
            self.totAlleles += 1.0
        }
    }
    
    func frequency( allele: String ) -> Double {
        if totAlleles > 0 {
            let top = self.counts[ allele ] ?? 0.0
            return top / self.totAlleles
        } else {
            return 0.0
        }
    }
    
    func Ho() -> Double {
        if numLoci > 0 {
            return numHets / numLoci
        } else {
            return 0.0
        }
    }
    
    func He() -> Double {
        var ret = 0.0
        
        // Bail on empty set.  He should be 0.0 if no alleles.
        if numAlleles == 0 {
            return 0.0
        }
        
        for allele in self.counts.keys {
            ret += pow( frequency(allele: allele), 2)
        }
        
        return (1.0 - ret)
    }
}



// MARK: - Conversions
extension AlleleFrequencies : CustomStringConvertible {
    var description: String {
        var ret = [String]()
        for allele in self.alleles {
            ret.append( "\(allele): \(self.frequency(allele: allele))")
        }
        return ret.joined(separator: "\n")
    }
}
