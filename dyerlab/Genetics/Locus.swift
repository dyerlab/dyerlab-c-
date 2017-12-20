//
//  Locus.swift
//  DLabGenetics
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation

class Locus  {
    var alleles: [String]
    var ploidy: Int {
        get {
            return self.alleles.count
        }
    }
    var isHeterozygote: Bool {
        get {
            return Set<String>(self.alleles).count > 1
        }
    }
    var isEmpty: Bool {
        get {
            return self.alleles.count > 0
        }
    }
    
    init() {
        self.alleles = [String]()
    }
    
    init( alleles: [String] ) {
        self.alleles = alleles
    }
    
}


extension Locus : Equatable {
    static func == (lhs: Locus, rhs: Locus ) -> Bool {
        if lhs.alleles == rhs.alleles {
            return true
        }
        return false
    }
}


// MARK: - Conversions
extension Locus : CustomStringConvertible {
    var description: String {
        return self.alleles.sorted().joined(separator: ":")
    }
    
    func toVector( alleles: [String] ) -> Vector {
        var ret = Vector(repeating: 0.0, count: alleles.count )
        
        for allele in self.alleles {
            if let idx = alleles.index(of: allele) {
                ret[idx] += 1.0
            }
        }
        
        return ret
    }
}


