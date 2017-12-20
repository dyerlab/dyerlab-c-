//
//  AMOVA.swift
//  DLabGenetics
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation
import Accelerate

func distAMOVA( loc1: Locus, loc2: Locus ) -> Double {
    if loc1.isEmpty || loc2.isEmpty || loc1 == loc2 {
        return 0.0
    }
    
    let allAlleles = loc1.alleles + loc2.alleles
    let alleles = Array<String>( Set<String>(allAlleles) )
    
    let v = loc1.toVector( alleles: alleles ) - loc2.toVector(alleles: alleles)
    let d = cblas_ddot( Int32(v.count), v, 1, v, 1 )
    return d
}
