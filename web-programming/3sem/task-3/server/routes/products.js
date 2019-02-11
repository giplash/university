import express from 'express';
import Controller from '../controllers/Products';
const router = express.Router();

router.get('/', Controller.getProducts);
router.post('/buy', Controller.buyProduct);
router.post('/add', Controller.addProduct);

export default router;