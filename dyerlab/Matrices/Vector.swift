//
//  Vector.swift
//  DLabMatrix
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation
import Accelerate

public typealias Vector = [Double]
infix operator **

public func **(left:Vector, right:Vector) -> Double {
    precondition(left.count == right.count)
    var d: Double = 0.0
    vDSP_dotprD(left, 1, right, 1, &d, vDSP_Length(left.count))
    return d
}

public func -(lhs: Vector, rhs:Vector) -> Vector {
    precondition( lhs.count == rhs.count )
    var ret = Vector(repeating: 0.0, count: lhs.count)
    for i in 1...lhs.count {
        ret[i] = lhs[i] - rhs[i]
    }
    return ret
}

public func +(lhs: Vector, rhs: Vector) -> Vector {
    precondition( lhs.count == rhs.count )
    var ret = Vector(repeating: 0.0, count: lhs.count)
    for i in 1...lhs.count {
        ret[i] = lhs[i] + rhs[i]
    }
    return ret
}

