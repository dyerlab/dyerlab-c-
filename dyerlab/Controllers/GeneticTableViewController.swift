//
//  GeneticTableViewController.swift
//  dyerlab
//
//  Created by Rodney Dyer on 12/20/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Cocoa

class GeneticTableViewController: NSViewController {
    
    @IBOutlet weak var GeneticTableView: NSTableView!
    var thePop: Population?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        makeTableForPopulation(population: loadArapatData())
        self.GeneticTableView!.delegate  = self
        self.GeneticTableView!.dataSource = self
        self.GeneticTableView!.reloadData()
    }
    
    func makeTableForPopulation(population: Population) {
        thePop =  population
        print("The population has \(thePop!.individuals.count) individuals")
        // remove all the current columns
        let columns = self.GeneticTableView.tableColumns
        columns.forEach {
            self.GeneticTableView.removeTableColumn($0)
        }
        
        // add the new columns
        let headers = population.keys
        for header in headers {
            let identifier = NSUserInterfaceItemIdentifier(header)
            let col: NSTableColumn = NSTableColumn(identifier: identifier )
            col.headerCell.title = header
            let sortDescriptor = NSSortDescriptor(key: header, ascending: true)
            col.sortDescriptorPrototype = sortDescriptor
            self.GeneticTableView!.addTableColumn(col)
        }
    }
}

// MARK: - Data Source & Delegate Functions
extension GeneticTableViewController:  NSTableViewDataSource, NSTableViewDelegate {

    func numberOfRows(in tableView: NSTableView ) -> Int {
        return thePop!.individuals.count
    }
    
    func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {
        let txt = tableColumn!.identifier.rawValue
        let object = self.thePop!.individuals[row].componentDescription(key: txt)
        return object
    }
    


}

