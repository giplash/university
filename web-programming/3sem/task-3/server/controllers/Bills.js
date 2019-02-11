import ProductsModel from '../models/Products';
import BillsModel from '../models/Bills';

export default class {
  static async getBills(req, res) {
    try {
      const bills = await BillsModel.fetchAll();
      res.json({
        bills,
        success: true,
        errorMessage: null
      });
    } catch(e) {
      res.json({
        products: null,
        success: false,
        errorMessage: e.message
      });
    }
  }
}