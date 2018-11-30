import Model from '../models/Products';

export default class {
  static async getProducts(req, res) {
    const products = await Model.fetchAll();
    res.json(products);
  }
}