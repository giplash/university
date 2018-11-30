import ProductsModel from '../models/Products';
import CardModel from '../models/Card';

export default class {
  static async getProducts(req, res) {
    try {
      const products = await ProductsModel.fetchAll();
      res.json({
        products,
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

  static async buyProduct(req, res) {
    try {
      const { id, quantity, cardData } = req.body;
      const balance = await CardModel.getBalance(cardData);
      const price = await ProductsModel.getPrice(id, quantity);
      if (balance < price) {
        res.json({
          success: false,
          errorMessage: 'You don\'t have enough money'
        });
      }
      await CardModel.reduceBalance(cardData, price);
      await ProductsModel.reduceQuantity(id, quantity);
      res.json({
        success: true,
        errorMessage: null
      });
    } catch(e) {
      res.json({
        success: false,
        errorMessage: e.message
      });
    }
  }

  static async addProduct(req, res) {
    try {
      const { id, name, price, quantity } = req.body;
      await ProductsModel.addProduct({ id, name, price, quantity});
      res.json({
        success: true,
        errorMessage: null
      });
    } catch(e) {
      res.json({
        success: false,
        errorMessage: e.message
      });
    }
  }
}