//
//  Individual.swift
//  DLabGenetics
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Foundation
import CoreLocation

enum IndividualDataType {
    case IndividualDataUnknown
    case IndividualDataStratum
    case IndividualDataLocation
    case IndividualDataExternal
    case IndividualDataLocus
}

class Individual {
    var strata: Dictionary<String,String>
    var external: Dictionary<String,Double>
    var loci: Dictionary<String,Locus>
    var location: CLLocationCoordinate2D?
    
    init() {
        self.strata = Dictionary<String,String>()
        self.external = Dictionary<String,Double>()
        self.loci = Dictionary<String,Locus>()
    }
    
    func keys() -> [String] {
        var ret = [String]()

        ret.append(contentsOf: self.strata.keys.sorted() )
        
        if self.location != nil {
            ret.append("Longitude")
            ret.append("Latitude")
        }
        
        ret.append(contentsOf: self.external.keys.sorted() )
        ret.append(contentsOf: self.loci.keys.sorted() )
        
        return ret
    }
    
    func dataTypeForKey( key: String ) -> IndividualDataType {
        if key == "Longitude" || key == "Latitude" {
            return IndividualDataType.IndividualDataLocation
        } else if self.strata.keys.contains(key) {
            return IndividualDataType.IndividualDataStratum
        } else if self.external.keys.contains( key ) {
            return IndividualDataType.IndividualDataExternal
        } else if self.loci.keys.contains(key) {
            return IndividualDataType.IndividualDataLocus
        } else {
            return IndividualDataType.IndividualDataUnknown
        }
    }
    
    func getStrata(key: String ) -> String {
        return self.strata[key] ?? ""
    }
    
    func getExternal( key: String ) -> Double {
        return self.external[key] ?? 0.0
    }
    
    func getLocus( key: String ) -> Locus {
        return self.loci[key] ?? Locus()
    }
    
    func getLatitude() -> Double? {
        return self.location?.latitude ?? nil
    }
    
    func getLongitude() -> Double? {
        return self.location?.longitude ?? nil
    }
    
    func setCoordinates(coord: CLLocationCoordinate2D ) {
        if CLLocationCoordinate2DIsValid(coord) {
            self.location = coord
        }
    }
    
    
    
}


// MARK: - Conversions
extension Individual : CustomStringConvertible {
    var description: String {
        var ret = [String]()
        for key in self.strata.keys.sorted() {
            ret.append(String("\(self.strata[key] ?? "")"))
        }
        if let val = self.getLatitude() {
            ret.append( String("\(val)"))
        }
        if let val = self.getLongitude() {
            ret.append( String("\(val)"))
        }
        for key in self.external.keys.sorted() {
            ret.append( String("\(String(describing: self.external[key]))") )
        }
        for key in self.loci.keys.sorted() {
            ret.append( String("\(self.loci[key] ?? Locus())"))
        }
        return ret.joined(separator: " ,")
    }
    
    func componentDescription( key: String ) -> String {
        if self.strata.keys.contains(key) {
            return self.strata[key]!
        } else if key == "Latitude", let lat = self.getLatitude() {
            return String("\(lat)")
        } else if key == "Longitude", let lon = self.getLongitude() {
            return String("\(lon)")
        } else if self.external.keys.contains(key) {
            return String("\(String(describing: self.external[key]))")
        } else if self.loci.keys.contains(key) {
            let val = self.loci[key]?.description
            return val!
        } else {
            return ""
        }
    }
}


