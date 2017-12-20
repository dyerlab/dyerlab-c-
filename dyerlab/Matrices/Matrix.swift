//
//  Matrix.swift
//  DLabMatrix
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation
import Accelerate

public class Matrix {
    internal var data: [Double]
    var rows: Int
    var columns: Int
    
    public init( data: [Double], rows: Int, columns: Int ) {
        self.data = data
        self.rows = rows
        self.columns = columns
    }
    
    public init(rows: Int, columns: Int) {
        self.rows = rows
        self.columns = columns
        self.data = [Double](repeating: 0.0, count: (rows*columns) )
    }

    func copy(with zone: NSZone? = nil) -> Matrix {
        let cp = Matrix(data: self.data, rows:self.rows, columns:self.columns)
        return cp
    }
    
    public subscript(row: Int, col: Int) -> Double {
        get {
            return data[(row * self.columns) + col]
        }
        set {
            self.data[(row * self.columns) + col] = newValue
        }
    }
    
    public func isSquare() -> Bool {
        return self.rows == self.columns
    }

    
    public func row(index:Int) -> [Double] {
        var r = [Double]()
        for col in 0..<columns {
            r.append(self[index,col])
        }
        return r
    }
    
    public func col(index:Int) -> [Double] {
        var c = [Double]()
        for row in 0..<rows {
            c.append(self[row,index])
        }
        return c
    }
    
}



// MARK: - Protocols
extension Matrix: CustomStringConvertible {
    public var description: String {
        var dsc = ""
        for row in 0..<rows {
            for col in 0..<self.columns {
                let s = String(self[row,col])
                dsc += s + " "
            }
            dsc += "\n"
        }
        return dsc
    }
}


// MARK: - Operator Overloads
extension Matrix: Equatable {
    
    public static func ==(left:Matrix, right:Matrix) -> Bool {
        if left.rows != right.rows {
            return false
        }
        if left.columns != right.columns {
            return false
        }
        for i in 0..<left.rows {
            for j in 0..<left.columns {
                if left[i,j] != right[i,j] {
                    return false
                }
            }
        }
        return true
    }

    public static func +(left: Matrix, right: Matrix) -> Matrix {
        precondition(left.rows == right.rows && left.columns == right.columns)
        let m = Matrix(data:left.data, rows: left.rows, columns: left.columns)
        for row in 0..<left.rows {
            for col in 0..<left.columns {
                m[row,col] += right[row,col]
            }
        }
        return m
    }
    
    public static func -(left: Matrix, right: Matrix) -> Matrix {
        precondition(left.rows == right.rows && left.columns == right.columns)
        let m = Matrix(data:left.data, rows: left.rows, columns: left.columns)
        for row in 0..<left.rows {
            for col in 0..<left.columns {
                m[row,col] -= right[row,col]
            }
        }
        return m
    }
    
    
    public static func *(left:Matrix, right:Matrix) -> Matrix {
        let lcp = left.copy()
        let rcp = right.copy()
        // can include the same transpose code as above
        var r = [Double](repeating: 1, count: lcp.rows * rcp.columns)
        vDSP_mmulD(lcp.data, 1, right.data, 1, &r, 1, vDSP_Length(lcp.rows), vDSP_Length(rcp.columns), vDSP_Length(rcp.rows))
        let dot = Matrix(data:r, rows:lcp.rows, columns:rcp.columns)
        return dot
    }
}

postfix operator ^
public postfix func ^(m:Matrix) -> Matrix {
    let t = Matrix(rows:m.columns, columns:m.rows)
    for row in 0..<m.rows {
        for col in 0..<m.columns {
            t[col,row] = m[row,col]
        }
    }
    return t
}








