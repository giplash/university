import express from 'express';
import Controller from '../controllers/Products';
const router = express.Router();

router.get('/', Controller.getProducts);

export default router;